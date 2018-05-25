#!/usr/bin/python2

import random, threading, socket, os, sys
from time import sleep

START_PORT = 26000
M_BITS = 8
MAX_NODES = 2**M_BITS

class entry():
    def __init__(self, num, identifier):
        self.start = self.location(num, identifier)
        self.interval = []
        if self.start > self.location(num+1, identifier):
            for i in range(MAX_NODES-self.start):
                self.interval.append(self.start+i)
            inter = [i for i in range(0, self.location(num+1, identifier))]
            for i in inter:
                self.interval.append(i)
        else:
            self.interval = [i for i in range(self.start, self.location(num+1, identifier))]
        self.node = identifier + 1

    def location(self, k, identifier):
        return (identifier + 2**(k-1)) % 2**M_BITS

class fingers():
    def __init__(self, identifier):
        self.li = [ entry(i+1, identifier) for i in range(M_BITS) ]

    def __getitem__(self, key):
        try:
            if key == -1:
                return [i for i in self.li]
            return self.li[key-1]
        except KeyError:
            print "that key does not exist"

class Node(object):
    # other is the port/id for a known (or non-existant) node
    def __init__(self, identifier, other=0):
        self.keys = []
        if other:
            self.keys = [i for i in range(256)]
        self.identifier = identifier
        self.leaving = 0
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.finger = fingers(self.identifier)
        self.predecessor = 0
        self.allkilled = 0
        havePort = 0

        while not havePort:
            try:
#                self.s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)	
                self.s.bind(("127.0.0.1", START_PORT + self.identifier))
                havePort = 1
            except socket.error, msg:
                pass
#        print "I have my port"
        self.thread = threading.Thread(target=self.run, args=())
        self.thread.start()

        tmp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            tmp.connect(("127.0.0.1", START_PORT + other))
            self.init_finger_table(other, tmp)
            self.update_others()
        except socket.error, msg:
            for i in range(1,M_BITS+1):
                self.finger[i].node = self.identifier
            self.predecessor = self.identifier

    def run(self):
        # listen for 1 connection at a time 
        while(not self.leaving):
            # c is how you will comm back to the person
            # the person that starts the connection will kill the connection
            self.s.listen(MAX_NODES)
            self.s.setblocking(0)
            try:
                c, addr = self.s.accept()
#                print "new connection"
                threading.Thread(target=self.parser, args=(c,)).start()
            except socket.error, msg:
                pass

        if self.allkilled:
            self.s.shutdown(socket.SHUT_RDWR)
            self.s.close()
            return

        # leaving_one who keys
        msg = "leaving_one " + str(self.identifier) + " " + str(self.finger[1].node) + " "
        for i in self.keys:
            msg += str(i) + " "
        msg += "\n"
        successor = self.finger[1].node
        suc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connector(suc, successor)
        suc.send(msg)
        suc.shutdown(socket.SHUT_RDWR)
        suc.close()

        self.s.setblocking(1)
        c, addr = self.s.accept()
        self.s.shutdown(socket.SHUT_RDWR)
        self.s.close()
        closer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        closer.connect(("127.0.0.1", START_PORT-1))
        closer.shutdown(socket.SHUT_RDWR)
        closer.close()

    def parser(self, sock):
            data = " "
            while data[-1] != '\n':
                    data += sock.recv(4096)
            data = data[:len(data) - 1]
            commands = data.split(";")
            msg = ""
            runs = 1
            for command in commands:
                words = command.split()
                if words[0] == "find_successor":
                    status = int(words[2])
                    while status:
                        msg = str(self.find_successor(int(words[1])))
                        sock.send(msg + '\n')
                        data = sock.recv(4096)
                        words = data.split()
                        status = int(words[2])
                    runs = 0
                elif words[0] == "predecessor":
                    msg += str(self.predecessor) + " "
                elif words[0] == "new_predecessor":
                    self.predecessor = int(words[1])
                elif words[0] == "coord":
                    msg += str(self.find_successor(int(words[1]))) + " \n"
                elif words[0] == "update_finger_table":
                    self.update_finger_table(int(words[1]), int(words[2]))

                elif words[0] == "successor":
                    msg += str(self.finger[1].node) + " "

                elif words[0] == "closest_preceding_finger":
                    msg += str(self.closest_preceding_finger(int(words[1]))) + " "

                elif words[0] == "keys":
                    ranges = self.check_range(self.identifier, int(words[1]), 3)
                    tmp_keys = [i for i in self.keys]
                    self.keys.sort()
                    for i in self.keys:
                        if self.in_range(ranges, i):
                            tmp_keys.remove(i)
                            msg += str(i) + " "
                    self.keys = tmp_keys
                elif words[0] == "leaving":
                    suc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                    self.connector(suc, self.finger[1].node)
                    msg = "leaving " + words[1] + " " + words[2] + " \n"
                    self.finger_clense(int(words[1]), int(words[2]))
                    suc.send(msg)
                    runs = 0
                elif words[0] == "leaving_one":
                    for i in range(0,len(words)-3):
                        self.keys.append(int(words[i+3]))
                    suc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                    self.connector(suc, self.finger[1].node)
                    msg = "leaving " + words[1] + " " + words[2] + " \n"
                    self.finger_clense(int(words[1]), int(words[2]))
                    suc.send(msg)
                    runs = 0

            # send the message
            if runs:
                msg += '\n'
                sock.send(msg)
            sock.shutdown(socket.SHUT_RDWR)
            sock.close()

    def init_finger_table(self, other, sock):
        # finger[1].node = other.find_successor(finger[1].start)
        msg = "find_successor " + str(self.finger[1].start) + " 1\n"
        words = self.request(msg, sock).split()
        self.finger[1].node = int(words[0])
        successor = self.finger[1].node

        suc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connector(suc, successor)
        msg = "keys " + str(self.identifier) + " \n"
        acks = self.request(msg, suc).split()
        for i in acks:
            self.keys.append(int(i))
        suc.shutdown(socket.SHUT_RDWR)
        suc.close()

        # predecessor = successor.predecessor
        suc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connector(suc, successor)
        msg = "predecessor \n"
        ack = self.request(msg, suc).split()
        self.predecessor = int(ack[0])
        suc.shutdown(socket.SHUT_RDWR)
        suc.close()

        # successor.predecessor = n
        # moving the keys to this person
        msg = "new_predecessor " + str(self.identifier) + " \n"
        suc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connector(suc, successor)
        acks = self.request(msg, suc).split()
        for i in acks:
            self.keys.append(int(i))
        suc.shutdown(socket.SHUT_RDWR)
        suc.close()

        for i in range(1, M_BITS):
            # if (finger[i+1].start E [n, finger[i].node))
            ranges = self.check_range(self.identifier, self.finger[i].node, 1)
            it_is = self.in_range(ranges, self.finger[i+1].start)
            if it_is:
                self.finger[i+1].node = self.finger[i].node
            # else finger[i+1].node = other.find_successor(finger[i+1].start)
            else:
                msg = "find_successor " + str(self.finger[i+1].start) + " 1\n"
                words = self.request(msg, sock).split()
                self.finger[i+1].node = int(words[0])
        sock.send("0 0 0\n")
        sock.shutdown(socket.SHUT_RDWR)
        sock.close()
        print ""

    # this one should be working
    def update_others(self):
        for i in range(1, M_BITS+1):
            val = 0
            num = 2**(i-1)
            if (self.identifier - num) < 0:
                val = MAX_NODES + self.identifier - num
            else:
                val = self.identifier - num

            # p = find_predecessor(n - pow(2, i-1))
            to_update = self.find_predecessor(val)

            if to_update == self.identifier:
                self.update_finger_table(self.identifier, i)
            else:
                # p.update_finger_table(n, i)
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                self.connector(sock, to_update)
                msg = "update_finger_table " + str(self.identifier) + " " + str(i) + " \n"
                self.request(msg, sock)
                sock.shutdown(socket.SHUT_RDWR)
                sock.close()

    # this one should be working
    def update_finger_table(self, s, i):
        # if (s E [n, finger[i].node))
        #ranges = self.check_range(self.identifier, self.finger[i].node, 1)
        ranges = self.check_range(self.finger[i].start, self.finger[i].node, 1)
        it_is = self.in_range(ranges, s)

        if it_is:
            # finger[i].node = s
            self.finger[i].node = s
            # p = predecessor
            to_update = self.predecessor
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.connector(sock, to_update)
            # p.update_finger_table(s,i)
            msg = "update_finger_table " + str(s) + " " + str(i) + " \n"
            self.request(msg, sock)
            sock.shutdown(socket.SHUT_RDWR)
            sock.close()

    # this one should be working
    def find_successor(self, val):
        # other = find_predecessor(val)
        other = self.find_predecessor(val)
        # return other.successor
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connector(sock, other)
        msg = "successor \n"
        ret_val = int(self.request(msg, sock).split()[0])
        sock.shutdown(socket.SHUT_RDWR)
        sock.close()
        return ret_val
        
    # this should be workign
    def find_predecessor(self, val):
        #if self.identifier == 0 and self.finger[1].node == 0:
            #return 0

        # other = self
        other = self.identifier
        # (other, other.successor]
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        successor = self.finger[1].node
        ranges = self.check_range(self.identifier, successor, 3)
        it_is = self.in_range(ranges, val)
        count = 0

        while not it_is:
            if count == 256:
                return other
            if other == self.identifier:
                other = self.closest_preceding_finger(val)
            else:
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                self.connector(sock, other)
                msg = "closest_preceding_finger " + str(val) + " \n"
                words = self.request(msg, sock).split()
                sock.shutdown(socket.SHUT_RDWR)
                sock.close()
                other = int(words[0])

            # other is updated
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.connector(sock, other)
            msg = "successor\n"
            successor = int(self.request(msg, sock).split()[0])
            sock.shutdown(socket.SHUT_RDWR)
            sock.close()
            ranges = self.check_range(other, successor, 3)
            it_is = self.in_range(ranges, val)
            count += 1

        return other

    # this should be working
    def closest_preceding_finger(self, val):
        ret_val = 0
        li = [i for i in range(1, M_BITS+1)]
        rev_li = li[::-1]
        for i in rev_li:
            ranges = self.check_range(self.identifier, val, 0) 
            it_is = self.in_range(ranges, self.finger[i].node)
            if it_is:
                return self.finger[i].node
        return self.identifier

    def request(self, msg, sock):
        sock.send(msg)
        return self.receiver(sock)

    def receiver(self, sock):
        data = " "
        while data[-1] != '\n':
            data += sock.recv(4096)
        return data[:len(data)-1]

    def connector(self, sock, other):
        connected = 0
#        print "connecting to:", START_PORT + other
        while not connected:
            try:
                sock.connect(("127.0.0.1", START_PORT+other))
                connected = 1
            except socket.error, msg:
                pass

    def check_range(self, beg, end, inclusion):
        ranges = []
        if beg > end or beg == end:
            ranges.append([i for i in range(beg, MAX_NODES)])
            ranges.append([i for i in range(end)])
        else:
            ranges.append([i for i in range(beg, end)])
    
        # [beg, end) || [beg, 255], [0, end)
        if inclusion == 0:
            # (beg, end)
            ranges[0].pop(0)
        elif inclusion == 1:
            # [beg, end)
            pass
        else:
            if inclusion == 3:
                ranges[0].pop(0)
            ranges[-1].append(end)
        return ranges

    def in_range(self, ranges, check):
        it_is = False
        if len(ranges) == 2:
            if check in ranges[0] or check in ranges[1]:
                it_is = True
        elif check in ranges[0]:
            it_is = True
        return it_is

    def finger_clense(self, node, successor):
        dat = self.finger[-1]
        start, end, new = -1, -1, -1
        for index,i in enumerate(dat):
            if i.node == node:
                i.node = successor

if __name__ == "__main__":
    #random.randint(0,0)
    args = sys.argv
    file0 = None
    f_exists = 0
    if len(args) > 1:
        if args[1] == "-g":
            file0 = open(args[2], 'w')
            f_exists = 1
    coord = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    have = 0
    while not have:
        try:
            coord.bind(("127.0.0.1", START_PORT - 1))
            have = 1
        except socket.error,msg:
            pass
#    a, b = .5, 800
#    os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % (a, b))
    coord.listen(1)
    nodes = {}
    for i in range(256):
        nodes[i] = ""
    free = [i for i in range(1,256)]
    taken = [0]

    tmp = Node(0, 1)
    nodes[0] = tmp
    while(1):
        try:
            instruction = raw_input("Enter new instruction:")
            words = instruction.split()
            if len(words) == 0: 
                continue 
            if len(words) == 1:
                if words[0] == "exit":
                    if f_exists:
                        file0.close()
                    for i in taken:
                        nodes[i].allkilled = 1
                        nodes[i].leaving = 1
                        nodes[i].thread.join()
                    break
            elif len(words) == 2:
                if words[0] == "join":
#                    print "joining"
                    num = int(words[1])
                    # if empty, create; else, already exists
                    if not(num in taken):
                        taken.append(num)
                        tmp = Node(num)
                        nodes[num] = tmp
                    else:
                        print "that node exists"

                elif words[0] == "leave":
#                    print "leaving"
                    num = int(words[1])
                    if num in taken:
                        taken.remove(num)
                        nodes[num].leaving = 1
                        nodes[num] = ""
                        coord.accept()
                    else:
                        print "that node doesn't exist"

                elif words[0] == "show":
                    if words[1] == "all":
                        taken.sort()
                        for i in taken:
                            ordered_keys = sorted(nodes[i].keys)
                            print i, 
                            if f_exists:
                                file0.write(str(i) + " ")
                            for j in ordered_keys:
                                print j,
                                if f_exists:
                                    file0.write(str(j) + " ")
                            print ""
                            if f_exists:
                                file0.write('\n')
                    elif words[1].isdigit():
                        num = int(words[1])
                        if num in taken:
                            ordered_keys = sorted(nodes[num].keys)
                            print num,
                            if f_exists:
                                file0.write(str(num) + " ")
                            for i in ordered_keys:
                                print i,
                                if f_exists:
                                    file0.write(str(i) + " ")
                            print ""
                            if f_exists:
                                file0.write('\n')

                elif words[0] == "finger":
                    print "finger table:"
                    dat = nodes[int(words[1])].finger[-1]
                    for i in dat:
                        print i.start, i.interval, i.node

            elif words[0] == "find" and len(words) == 3:
#                print "finding"
                num = int(words[1])
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                if num in taken:
                    have = 0
                    while not have:
                        try:
                            sock.connect(("127.0.0.1", START_PORT + num))
                            have = 1
                        except socket.error, msg:
                            pass
                    message = "coord " + words[2] + '\n'
                    sock.send(message)
                    #c, addr = coord.accept()
                    data = " "
                    while data[-1] != "\n":
                        data += sock.recv(4096)
                    print data
                    sock.shutdown(socket.SHUT_RDWR)
                    sock.close()
                else:
                    print "that node doesn't exist"

        except ValueError:      #KeyboardInterrupt: 
            if f_exists:
                file0.close()
            for i in taken:
                nodes[i].allkilled = 1
                nodes[i].leaving = 1
                nodes[i].thread.join()
            break
    print "Bye"
