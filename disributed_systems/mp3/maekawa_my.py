#@created 24th April, 2015 SA
#
#!/usr/bin/env python
import socket, sys, thread, threading, time, readline, io, random, re, os, subprocess, datetime
#from nodes import process_1, process_2, process_3, process_4, process_5, process_6, process_7, process_8, process_9 
from threading import Thread, Lock
#cs_int
#next_req
#tot_exec_time
process_1_state = 'RELEASED'
process_1_voted = 'FALSE'
process_2_state = 'RELEASED'
process_2_voted = 'FALSE'
process_3_state = 'RELEASED'
process_3_voted = 'FALSE'
process_4_state = 'RELEASED'
process_4_voted = 'FALSE'
process_5_state = 'RELEASED'
process_5_voted = 'FALSE'
process_6_state = 'RELEASED'
process_6_voted = 'FALSE'
process_7_state = 'RELEASED'
process_7_voted = 'FALSE'
process_8_state = 'RELEASED'
process_8_voted = 'FALSE'
process_9_state = 'RELEASED'
process_9_voted = 'FALSE'
process_1_queue = []
process_2_queue = []
process_3_queue = []
process_4_queue = []
process_5_queue = []
process_6_queue = []
process_7_queue = []
process_8_queue = []
process_9_queue = []
process_1_counter = 0
process_2_counter = 0
process_3_counter = 0
process_4_counter = 0
process_5_counter = 0
process_6_counter = 0
process_7_counter = 0
process_8_counter = 0
process_9_counter = 0
mutex = Lock()
#-----------------------------------------------------------------------------------
def code_exit():
	global tot_exec_time
	time.sleep(int(tot_exec_time))
	print "Bye..!"
	os._exit(0)
#	print "hahahahaha"
#thread.start_new_thread(code_exit, ())
#-----------------------------------------------------------------------------------
TCP_IP = '127.0.0.1'
TCP_PORT_MAIN = '8000'
TCP_PORT_PROCESS1 = '8001'
TCP_PORT_PROCESS2 = '8002'
TCP_PORT_PROCESS3 = '8003'
TCP_PORT_PROCESS4 = '8004'
TCP_PORT_PROCESS5 = '8005'
TCP_PORT_PROCESS6 = '8006'
TCP_PORT_PROCESS7 = '8007'
TCP_PORT_PROCESS8 = '8008'
TCP_PORT_PROCESS9 = '8009'
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, int(TCP_PORT_MAIN)))
s.listen(1)
#----------------------------------------------------------------------------------------------------
def send_thread_at_will(msg, dest):
	global options
	have = 0
	while (have == 0):
		try:
			s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)		
			s.connect(('', int(dest)))
			s.send(msg)
			s.close()
			have = 1
			if (options == 1):
				print "data", msg
		except error,msg:
			have = 0
			pass
			
def deadlock_detection_thread():
	global process_1_state, process_2_state, process_3_state, process_4_state, process_5_state, process_6_state, process_7_state, process_8_state, process_9_state, process_1_voted, process_2_voted, process_3_voted, process_4_voted, process_5_voted, process_6_voted, process_7_voted, process_8_voted, process_9_voted, process_1_queue, process_2_queue, process_3_queue, process_4_queue, process_5_queue, process_6_queue, process_7_queue, process_8_queue, process_9_queue, process_1_counter, process_2_counter, process_3_counter, process_4_counter, process_5_counter, process_6_counter, process_7_counter, process_8_counter, process_9_counterr
	local_counter = 0
	time.sleep(8)
	while True:
		local_counter = 0	
		time.sleep(4)
		if (process_1_state == 'HELD'):
			local_counter += 1
		if (process_2_state == 'HELD'):
			local_counter += 1
		if (process_3_state == 'HELD'):
			local_counter += 1
		if (process_4_state == 'HELD'):
			local_counter += 1
		if (process_5_state == 'HELD'):
			local_counter += 1
		if (process_6_state == 'HELD'):
			local_counter += 1
		if (process_7_state == 'HELD'):
			local_counter += 1
		if (process_8_state == 'HELD'):
			local_counter += 1
		if (process_9_state == 'HELD'):
			local_counter += 1
		if (local_counter >= 2):
			print "there is a deadlock"
		if (local_counter == 0):
			t = max(process_1_counter, process_2_counter, process_3_counter, process_4_counter, process_5_counter)
#			t = random.randint(1,5)
			print 'max =', t
			if (t != process_1_counter):
				process_1_counter = 0
			elif (t != process_2_counter):
			 	process_2_counter = 0
			elif (t != process_3_counter):
				process_3_counter = 0
			elif (t != process_4_counter):
				process_4_counter = 0
			elif (t != process_5_counter):
				process_5_counter = 0
			elif (t != process_6_counter):
				process_5_counter = 0
			elif (t != process_7_counter):
				process_7_counter = 0
			process_8_counter = 0
			process_9_counter = 0
			t = t + 5
#			if(t == 1):
#				process_1_counter = process_1_counter + 4
#			elif(t == 2):
#				process_2_counter = process_2_counter + 4
#			elif(t == 3):
#				process_3_counter = process_3_counter + 4
#			elif(t == 4):
#				process_4_counter = process_4_counter + 4
#			elif(t == 5):
#				process_5_counter = process_5_counter + 4
#		time.sleep(0.01)
#		process_1_state = 'RELEASED'
#		process_1_voted = 'FALSE'
#		process_2_state = 'RELEASED'
#		process_2_voted = 'FALSE'
#		process_3_state = 'RELEASED'
#		process_3_voted = 'FALSE'
#		process_4_state = 'RELEASED'
#		process_4_voted = 'FALSE'
#		process_5_state = 'RELEASED'
#		process_5_voted = 'FALSE'
#		process_6_state = 'RELEASED'
#		process_6_voted = 'FALSE'
#		process_7_state = 'RELEASED'
#		process_7_voted = 'FALSE'
#		process_8_state = 'RELEASED'
#		process_8_voted = 'FALSE'
#		process_9_state = 'RELEASED'
#		process_9_voted = 'FALSE'
#		process_1_queue = []
#		process_2_queue = []
#		process_3_queue = []
#		process_4_queue = []
#		process_5_queue = []
#		process_6_queue = []
#		process_7_queue = []
#		process_8_queue = []
#		process_9_queue = []
			
			
class processes:
	def __init__(self):
		pass
	def process_init(self):
		self.state = 'RELEASED'
		self.voted = 'FALSE'			
	def request(self):
		state = 'WANTED'
		try:
			s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			s.connect((TCP_IP, 8000))
			s.send('poked you')
			t = s.recv(1024)
#			print t
			s.close
			if (thread1_request_ack == 8):
				state = 'HELD'
		except socket.error,msg:
			pass
	def exit(self):
		state = 'RELEASED'
		#HAVE TO SEND RELEASE MSG TO ALL THE PROCESSES
class Node:
	def __init__(self):
		pass
#-------------------------------------------------------------------------------------------------
def process_1_listen():
	global process_1_state, process_1_voted, process_1_queue, process_1_counter, options
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS1)))
	s.listen(20)
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
#			print "options for 1 is, ", options
			#print "process_1_queue", process_1_queue
			data = data.rstrip('\n')	
			words = data.split(' ')
			if (options == 1):
				print "data1", data
			if (words[0] == 'ping'):
				if ((process_1_state == 'HELD') or (process_1_voted == 'TRUE')):
					process_1_queue.append(int(words[2]))
				else:
					Thread(target = send_thread_at_will, args=('pong 1 8001', int(words[2]))).start()
					process_1_voted = 'TRUE'
			elif (words[0] == 'release'):
				if not process_1_queue:
					process_1_voted = 'FALSE'
				else:
					Thread(target = send_thread_at_will, args=('pong 1 8001', int(process_1_queue[0]))).start()
					process_1_voted = 'TRUE'
					process_1_queue.pop()
			elif (words[0] == 'pong'):
				process_1_counter = process_1_counter + 1
			else:
				print "dont send me crap in 1"
				pass
	conn.close()

def run_by_queue2():
	global process_2_queue
	while True:
		time.sleep(3)
		if not process_2_queue:
			pass
		else:
			temp1 = process_queue[0]
			temp = process_2_queue[0][1]	
			for i in range(len(process_2_queue)):
				if(process_2_queue[i][1] < temp):
					temp = process_2_queue[i][1]		#got the earliest time stamp
					temp1 = process_2_queue[0]
			print "earliest arrived packet = ", temp1
			#have to send this packet back
		
def process_2_listen():
	global process_2_state, process_2_voted, process_2_queue, process_2_counter, options
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS2)))
	s.listen(20)
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
#			print "data2", data
#			print "options for 2 is, ", options
#			print "data2", data
			#print "process_1_queue", process_1_queue
			if (options == 1):
				print "data2", data
			data = data.rstrip('\n')	
			words = data.split(' ')
			if (words[0] == 'ping'):
				if ((process_2_state == 'HELD') or (process_2_voted == 'TRUE')):
					process_2_queue.append(int(words[2]))
				else:
					Thread(target = send_thread_at_will, args=('pong 2 8002', int(words[2]))).start()
					process_2_voted = 'TRUE'
			elif (words[0] == 'release'):
				if not process_2_queue:
					process_2_voted = 'FALSE'
				else:
					Thread(target = send_thread_at_will, args=('pong 2 8002', int(process_2_queue[0]))).start()
					process_2_voted = 'TRUE'
					process_2_queue.pop()
			elif (words[0] == 'pong'):
				process_2_counter = process_2_counter + 1
			else:
				print "dont send me crap in 2"
				pass
	conn.close()


def process_3_listen():
	global process_3_state, process_3_voted, process_3_queue, process_3_counter, options
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS3)))
	s.listen(20)
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
#			print "data3", data
#			print "process_3_queue", process_3_queue
#			print "3data = ", data		
			if (options == 1):
				print "data3", data
			data = data.rstrip('\n')	
			words = data.split(' ')
			if (words[0] == 'ping'):
				if ((process_3_state == 'HELD') or (process_3_voted == 'TRUE')):
					process_3_queue.append(int(words[2]))
				else:
					Thread(target = send_thread_at_will, args=('pong 3 8003', int(words[2]))).start()
					process_3_voted = 'TRUE'
			elif (words[0] == 'release'):
				if not process_3_queue:
					process_3_voted = 'FALSE'
				else:
					Thread(target = send_thread_at_will, args=('pong 3 8003', int(process_3_queue[0]))).start()
					process_3_queue.pop()
					process_3_voted = 'TRUE'
			elif (words[0] == 'pong'):
				process_3_counter = process_3_counter + 1
			else:
				print "dont send me crap"
				pass
	conn.close()

def process_4_listen():
	global process_4_state, process_4_voted, process_4_queue, process_4_counter, options
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS4)))
	s.listen(20)
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
#			print "data4", data
#			print "process_4_queue", process_4_queue
			if (options == 1):
				print "data4", data
			data = data.rstrip('\n')	
			words = data.split(' ')
			if (words[0] == 'ping'):
				if ((process_4_state == 'HELD') or (process_4_voted == 'TRUE')):
					process_4_queue.append(int(words[2]))
				else:
					Thread(target = send_thread_at_will, args=('pong 4 8004', int(words[2]))).start()
					process_4_voted = 'TRUE'
			elif (words[0] == 'release'):
				if not process_4_queue:
					process_4_voted = 'FALSE'
				else:
					Thread(target = send_thread_at_will, args=('pong 4 8004', int(process_4_queue[0]))).start()
					process_4_voted = 'TRUE'	
					process_4_queue.pop()
			elif (words[0] == 'pong'):
				process_4_counter = process_4_counter + 1
			else:
				print "dont send me crap"
				pass		
	conn.close()
	
def process_5_listen():
	global process_5_state, process_5_voted, process_5_queue, process_5_counter, options
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS5)))
	s.listen(20)
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
#			print "data5", data
#			print "process_5_queue", process_5_queue
			if (options == 1):
				print "data5", data
			data = data.rstrip('\n')	
			words = data.split(' ')
			if (words[0] == 'ping'):
				if ((process_5_state == 'HELD') or (process_5_voted == 'TRUE')):
					process_5_queue.append(int(words[2]))
				else:
					Thread(target = send_thread_at_will, args=('pong 5 8005', int(words[2]))).start()
					process_5_voted = 'TRUE'
			elif (words[0] == 'release'):
				if not process_5_queue:
					process_5_voted = 'FALSE'
				else:
					Thread(target = send_thread_at_will, args=('pong 5 8005', int(process_5_queue[0]))).start()
					process_5_voted = 'TRUE'
					process_5_queue.pop()
			elif (words[0] == 'pong'):
				process_5_counter = process_5_counter + 1
			else:
				print "dont send me crap"
				pass
	conn.close()
	
def process_6_listen():
	global process_6_state, process_6_voted, process_6_queue, process_6_counter, options
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS6)))
	s.listen(20)
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
#			print "data6", data	
#			print "process_6_queue", process_6_queue
			if (options == 1):
				print "data6", data
			data = data.rstrip('\n')	
			words = data.split(' ')
			if (words[0] == 'ping'):
				if ((process_6_state == 'HELD') or (process_6_voted == 'TRUE')):
					process_6_queue.append(int(words[2]))
				else:
					Thread(target = send_thread_at_will, args=('pong 6 8006', int(words[2]))).start()
					process_6_voted = 'TRUE'
			elif (words[0] == 'release'):
				if not process_6_queue:
					process_6_voted = 'FALSE'
				else:
					Thread(target = send_thread_at_will, args=('pong 6 8006', int(process_6_queue[0]))).start()
					process_6_voted = 'TRUE'
					process_6_queue.pop()
			elif (words[0] == 'pong'):
				process_6_counter = process_6_counter + 1
			else:
				print "dont send me crap"
				pass
	conn.close()

def process_7_listen():
	global process_7_state, process_7_voted, process_7_queue, process_7_counter, options
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS7)))
	s.listen(20)
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
#			print "data7", data
#			print "process_7_queue", process_7_queue
			data = data.rstrip('\n')	
			words = data.split(' ')
			if (options == 1):
				print "data7", data
			if (words[0] == 'ping'):
				if ((process_7_state == 'HELD') or (process_7_voted == 'TRUE')):
					process_7_queue.append(int(words[2]))
				else:
					Thread(target = send_thread_at_will, args=('pong 7 8007', int(words[2]))).start()
					process_7_voted = 'TRUE'
			elif (words[0] == 'release'):
				if not process_7_queue:
					process_7_voted = 'FALSE'
				else:
					Thread(target = send_thread_at_will, args=('pong 7 8007', int(process_7_queue[0]))).start()
					process_7_voted = 'TRUE'	
					process_7_queue.pop()
			elif (words[0] == 'pong'):
				process_7_counter = process_7_counter + 1
			else:
				print "dont send me crap"
				pass
	conn.close()

def process_8_listen():
	global process_8_state, process_8_voted, process_8_queue, process_8_counter, options
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS8)))
	s.listen(20)
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
#			print "data8", data
#			print "process_8_queue", process_8_queue
			if (options == 1):
				print "data8", data
			data = data.rstrip('\n')	
			words = data.split(' ')
			if (words[0] == 'ping'):
				if ((process_8_state == 'HELD') or (process_8_voted == 'TRUE')):
					process_8_queue.append(int(words[2]))
				else:
					Thread(target = send_thread_at_will, args=('pong 8 8008', int(words[2]))).start()
					process_8_voted = 'TRUE'
			elif (words[0] == 'release'):
				if not process_8_queue:
					process_8_voted = 'FALSE'
				else:
					Thread(target = send_thread_at_will, args=('pong 8 8008', int(process_8_queue[0]))).start()
					process_8_voted = 'TRUE'	
					process_8_queue.pop()
			elif (words[0] == 'pong'):
				process_8_counter = process_8_counter + 1
			else:
				print "dont send me crap"
				pass
	conn.close()

def process_9_listen():
	global process_9_state, process_9_voted, process_9_queue, process_9_counter, options
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS9)))
	s.listen(20)
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
#			print "data9", data
#			print "options9", options
#			print "process_9_queue", process_9_queue
			if (options == 1):
				print "data9", data
			data = data.rstrip('\n')	
			words = data.split(' ')
			if (words[0] == 'ping'):
				if ((process_9_state == 'HELD') or (process_9_voted == 'TRUE')):
					process_9_queue.append(int(words[2]))
				else:
					Thread(target = send_thread_at_will, args=('pong 9 8009', int(words[2]))).start()
					process_9_voted = 'TRUE'
			elif (words[0] == 'release'):
				if not process_9_queue:
					process_9_voted = 'FALSE'
				else:
					Thread(target = send_thread_at_will, args=('pong 1 8001', int(process_9_queue[0]))).start()
					process_9_voted = 'TRUE'
					process_9_queue.pop()
			elif (words[0] == 'pong'):
				process_9_counter = process_9_counter + 1
			else:
				print "dont send me crap"
				pass
	conn.close()
#--------------------------------------------------------------
def process_1():
	global cs_int, next_req, tot_exec_time, process_1_state, process_1_voted, process_1_counter, options
	#init
	process_1_state = 'RELEASED'
	process_1_voted = 'FALSE'
	while True:
		#request
		time.sleep(int(next_req))
		process_1_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8001"
		if not mutex.acquire():
			time.sleep(0.5)
			pass
		else:
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()	
					#wait for reply from all the processes
			while True:
				if (process_1_counter >= 5):
					process_1_counter = 0
					break
				else:
					time.sleep(0.5)
#					print "counter1 = ", process_1_counter
					pass
			#held
			process_1_state = 'HELD'
			print "Process1CS -> Time:%s, Thread_identifier:node1, node-list: 1 2 3 4 7",  datetime.datetime.now()
			time.sleep(int(cs_int))
			#exit
			process_1_state = 'RELEASED'
			#multicast release to all processes in condition
			curr_time = datetime.datetime.now().time()
			msg_to_send = "release" + " " + str(curr_time) + " " + "8001"
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()
			mutex.release()
					
def process_2():
	global cs_int, next_req, tot_exec_time, process_2_state, process_2_voted, process_2_counter, options
	#init
	process_2_state = 'RELEASED'
	process_2_voted = 'FALSE'
	while True:
		#request
		time.sleep(int(next_req))
		process_2_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8002"
		if not mutex.acquire():
			time.sleep(0.5)
			pass
		else:
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()	
					#wait for reply from all the processes
			while True:
				if (process_2_counter >= 5):
					process_2_counter = 0
					break
				else:
					time.sleep(0.5)
#					print "counter2 = ", process_2_counter
					pass
			#held
			process_2_state = 'HELD'
			print "Process2CS -> Time:%s, Thread_identifier:node2, node-list: 1 2 3 5 8",  datetime.datetime.now()
			time.sleep(int(cs_int))
			#exit
			process_2_state = 'RELEASED'
			#multicast release to all processes in condition
			curr_time = datetime.datetime.now().time()
			msg_to_send = "release" + " " + str(curr_time) + " " + "8002"
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()
			mutex.release()
def process_3():
	global cs_int, next_req, tot_exec_time, process_3_state, process_3_voted, process_3_counter, options
	#init
	process_3_state = 'RELEASED'
	process_3_voted = 'FALSE'
	while True:
		#request
		time.sleep(int(next_req))
		process_3_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8003"		
		if not mutex.acquire():
			time.sleep(0.5)
			pass
		else:
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()	
					#wait for reply from all the processes
			while True:
				if (process_3_counter >= 5):
					process_3_counter = 0
					break
				else:
					time.sleep(0.5)
#					print "counter3 = ", process_3_counter
					pass
			#held
			process_3_state = 'HELD'
			print "Process3CS -> Time:%s, Thread_identifier:node3, node-list: 1 2 3 6 9",  datetime.datetime.now()
			time.sleep(int(cs_int))
			#exit
			process_3_state = 'RELEASED'
			#multicast release to all processes in condition
			curr_time = datetime.datetime.now().time()
			msg_to_send = "release" + " " + str(curr_time) + " " + "8003"		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()
			mutex.release()
					
def process_4():
	global cs_int, next_req, tot_exec_time, process_4_state, process_4_voted, process_4_counter, options
	#init
	process_4_state = 'RELEASED'
	process_4_voted = 'FALSE'
	while True:
		#request
		time.sleep(int(next_req))
		process_4_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8004"		
		if not mutex.acquire():
			time.sleep(0.5)
			pass
		else:
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()	
					#wait for reply from all the processes
			while True:
				if (process_4_counter >= 5):
					process_4_counter = 0
					break
				else:
					time.sleep(0.5)
#					print "counter4 = ", process_4_counter
					pass
			#held
			process_4_state = 'HELD'
			print "Process4CS -> Time:%s, Thread_identifier:node4, node-list: 1 4 5 6 7",  datetime.datetime.now()
			time.sleep(int(cs_int))
			#exit
			process_4_state = 'RELEASED'
			#multicast release to all processes in condition
			curr_time = datetime.datetime.now().time()
			msg_to_send = "release" + " " + str(curr_time) + " " + "8004"				
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()
			mutex.release()
					
def process_5():
	global cs_int, next_req, tot_exec_time, process_5_state, process_5_voted, process_5_counter, options
	#init
	process_5_state = 'RELEASED'
	process_5_voted = 'FALSE'
	while True:
		#request
		time.sleep(int(next_req))
		process_5_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8005"
		if not mutex.acquire():
			time.sleep(0.5)
			pass
		else:
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()	
					#wait for reply from all the processes
			while True:
				if (process_5_counter >= 5):
					process_5_counter = 0
					break
				else:
					time.sleep(0.5)
#					print "counter5 = ", process_5_counter
					pass
			#held
			process_5_state = 'HELD'
			print "Process5CS -> Time:%s, Thread_identifier:node5, node-list: 2 4 5 6 8",  datetime.datetime.now()
			time.sleep(int(cs_int))
			#exit
			process_5_state = 'RELEASED'
			#multicast release to all processes in condition
			curr_time = datetime.datetime.now().time()
			msg_to_send = "release" + " " + str(curr_time) + " " + "8005"
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()
			mutex.release()

def process_6():
	global cs_int, next_req, tot_exec_time, process_6_state, process_6_voted, process_6_counter, options
	#init
	process_6_state = 'RELEASED'
	process_6_voted = 'FALSE'
	while True:
		#request
		time.sleep(int(next_req))
		process_6_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8006"
		if not mutex.acquire():
			time.sleep(0.5)
			pass
		else:
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()	
					#wait for reply from all the processes
			while True:
				if (process_6_counter >= 5):
					process_6_counter = 0
					break
				else:
					time.sleep(0.5)
#					print "counter6 = ", process_6_counter
					pass
			#held
			process_6_state = 'HELD'
			print "Process6CS -> Time:%s, Thread_identifier:node6, node-list: 3 4 5 6 9",  datetime.datetime.now()
			time.sleep(int(cs_int))
			#exit
			process_6_state = 'RELEASED'
			#multicast release to all processes in condition
			curr_time = datetime.datetime.now().time()
			msg_to_send = "release" + " " + str(curr_time) + " " + "8006"
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()
			mutex.release()
					
def process_7():
	global cs_int, next_req, tot_exec_time, process_7_state, process_7_voted, process_7_counter, options
	#init
	process_7_state = 'RELEASED'
	process_7_voted = 'FALSE'
	while True:
		#request
		time.sleep(int(next_req))
		process_7_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8007"
		if not mutex.acquire():
			time.sleep(0.5)
			pass
		else:
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()	
					#wait for reply from all the processes
			while True:
				if (process_7_counter >= 5):
					process_7_counter = 0
					break
				else:
					time.sleep(0.5)
#					print "counter7 = ", process_7_counter
					pass
			#held
			process_7_state = 'HELD'
			print "Process7CS -> Time:%s, Thread_identifier:node7, node-list: 1 4 7 8 9",  datetime.datetime.now()
			time.sleep(int(cs_int))
			#exit
			process_7_state = 'RELEASED'
			#multicast release to all processes in condition
			curr_time = datetime.datetime.now().time()
			msg_to_send = "release" + " " + str(curr_time) + " " + "8007"
			Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()
			mutex.release()
def process_8():
	global cs_int, next_req, tot_exec_time, process_8_state, process_8_voted, process_8_counter, options
	#init
	process_8_state = 'RELEASED'
	process_8_voted = 'FALSE'
	while True:
		#request
		time.sleep(int(next_req))
		process_8_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8008"
		if not mutex.acquire():
			time.sleep(0.5)
			pass
		else:
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()	
					#wait for reply from all the processes
			while True:
				if (process_8_counter >= 5):
					process_8_counter = 0
					break
				else:
					time.sleep(0.5)
#					print "counter8 = ", process_8_counter
					pass
			#held
			process_8_state = 'HELD'
			print "Process8CS -> Time:%s, Thread_identifier:node8, node-list: 2 5 7 8 9",  datetime.datetime.now()
			time.sleep(int(cs_int))
			#exit
			process_8_state = 'RELEASED'
			#multicast release to all processes in condition
			curr_time = datetime.datetime.now().time()
			msg_to_send = "release" + " " + str(curr_time) + " " + "8008"
			Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8005)).start()		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()
			mutex.release()
def process_9():
	global cs_int, next_req, tot_exec_time, process_9_state, process_9_voted, process_9_counter, options
	#init
	process_9_state = 'RELEASED'
	process_9_voted = 'FALSE'
	while True:
		#request
		time.sleep(int(next_req))
		process_9_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8009"
		if not mutex.acquire():
			time.sleep(0.5)
			pass
		else:
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()	
					#wait for reply from all the processes
			while True:
				if (process_9_counter >= 5):
					process_9_counter = 0
					break
				else:
					time.sleep(0.5)
#					print "counter9 = ", process_9_counter
					pass
			#held
			process_9_state = 'HELD'
			print "Process9CS -> Time:%s, Thread_identifier:node9, node-list: 3 6 7 8 9",  datetime.datetime.now()
			time.sleep(int(cs_int))
			#exit
			process_9_state = 'RELEASED'
			#multicast release to all processes in condition
			curr_time = datetime.datetime.now().time()
			msg_to_send = "release" + " " + str(curr_time) + " " + "8009"
			Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8006)).start()		
			Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8008)).start()
			Thread(target = send_thread_at_will, args=(msg_to_send, 8009)).start()
			mutex.release()
					
#--------------------------------------------------------------------------------------------------
#this will do the listening part and print incoming messagaes
#a = processes()
#thread.start_new_thread(a.test, ())

#thread.start_new_thread(deadlock_detection_thread, ())

if __name__ == "__main__":
	global cs_int, next_req, tot_exec_time, options
	args = sys.argv
	if ((len(args) < 4) or (len(args) > 5)):
		print "incorrect arguments provided"
		print "Bye..!"
		os._exit(0)
	else:
		cs_int = args[1]
		next_req = args[2]
		tot_exec_time = args[3]
		if (len(args) == 5):
			options = int(args[4])
		else:
			options = 0
	print "your option was ", options
	thread.start_new_thread(process_1, ())
	thread.start_new_thread(process_2, ())
	thread.start_new_thread(process_3, ())
	thread.start_new_thread(process_4, ())
	thread.start_new_thread(process_5, ())
	thread.start_new_thread(process_6, ())
	thread.start_new_thread(process_7, ())
	thread.start_new_thread(process_8, ())
	thread.start_new_thread(process_9, ())
	thread.start_new_thread(process_1_listen, ())
	thread.start_new_thread(process_2_listen, ())
	thread.start_new_thread(process_3_listen, ())
	thread.start_new_thread(process_4_listen, ())
	thread.start_new_thread(process_5_listen, ())
	thread.start_new_thread(process_6_listen, ())
	thread.start_new_thread(process_7_listen, ())
	thread.start_new_thread(process_8_listen, ())
	thread.start_new_thread(process_9_listen, ())
	thread.start_new_thread(run_by_queue2, ())		


while 1:
	try:
		instruction = raw_input("")
		words = instruction.split()
		if (words == 'gogo'):
			print "gogo"		
		elif (words == 'nono'):
			print "nono"		
		else:
			print "dead end - something is wrong"
	except KeyboardInterrupt:	#ValueError:						#KeyboardInterrupt:
		break
		print "Bye"
