#@created 24th April, 2015 SA
#
#!/usr/bin/env python
import socket, sys, thread, threading, time, readline, io, random, re, os, subprocess, datetime
#from nodes import process_1, process_2, process_3, process_4, process_5, process_6, process_7, process_8, process_9 
from threading import Thread, Lock
cs_int = 15
next_req = 5
tot_exec_time = 13
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
mutex1 = Lock()
#-----------------------------------------------------------------------------------
def code_exit():
	global tot_exec_time
	time.sleep(int(tot_exec_time))
	print "Bye..!"
	os._exit(0)
	print "hahahahaha"
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
	have = 0
	while (have == 0):
		try:
			s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)		
			s.connect(('', int(dest)))
			s.send(msg)
			s.close()
			have = 1
		except socket.error,msg:
			have = 0
			pass
			
#------------------------------------------------------------------------------------
def process_1_temp():
	global process_1_queue, process_1_counter
	time.sleep(7.5)
	while True:
		if not len(process_1_queue):
			pass
		else:
			if (process_1_state == 'HELD'):
				pass
			else:
				mutex1.acquire()
				temp_time = process_1_queue[0][1]
				temp_port = process_1_queue[0][2]
				index = 0
				for i in range(len(process_1_queue)):
					if (process_1_queue[i][0] == "pong"):
						proces_1_counter = process_1_counter + 1
					if ((process_1_queue[i][0] == "ping") or (process_1_queue[i][0] == "release")):	
						if (process_1_queue[i][1] < temp_time):
							temp_time = process_1_queue[i][1]
							temp_port = process_1_queue[i][2]
							index = i
				Thread(target = send_thread_at_will, args=('pong 1 8001', int(process_1_queue[index][2]))).start()
				process_1_queue[index].pop()
				mutex1.release()							

def process_1_listen():
	global process_1_queue
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, int(TCP_PORT_PROCESS1)))
	s.listen(20)
	process_1_counter = 0
#	thread.start_new_thread(process_1_temp, ())
	while True:
		conn, addr = s.accept()
		data = conn.recv(1024)
		if data:
			mutex1.acquire()
			data = data.rstrip('\n')	
			words = data.split(' ')
			process_1_queue.append([words[0], words[1], words[2]])
			print "check process1 = ", process_1_queue
			mutex1.release()
	conn.close()
#--------------------------------------------------------------

def process_1():
	global cs_int, next_req, tot_exec_time, process_1_state, process_1_voted, process_1_counter, process_1_queue
	#init
	process_1_state = 'RELEASED'
	while True:
		#request
		time.sleep(int(next_req))
		process_1_state = 'WANTED'
				#multicast request messages to all processes
		curr_time = datetime.datetime.now().time()
		msg_to_send = "ping" + " " + str(curr_time) + " " + "8001"
		Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
		Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
		Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
		Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()		
				#wait for reply from all the processes
		while True:
			if (process_1_counter >= 5):
				process_1_counter = 0
				break
			else:
				time.sleep(0.5)
				print "counter1 = ", process_1_counter
				pass
		#held
		process_1_state = 'HELD'
#		print "Process1CS -> Time:%s, Thread_identifier:node1, node-list: 1 2 3 4 7",  datetime.datetime.now()
		time.sleep(int(cs_int))
		#exit
		process_1_state = 'RELEASED'
		#multicast release to all processes in condition
		curr_time = datetime.datetime.now().time()
		msg_to_send = "release" + " " + str(curr_time) + " " + "8001"
#		Thread(target = send_thread_at_will, args=(msg_to_send, 8001)).start()
#		Thread(target = send_thread_at_will, args=(msg_to_send, 8002)).start()		
#		Thread(target = send_thread_at_will, args=(msg_to_send, 8003)).start()
#		Thread(target = send_thread_at_will, args=(msg_to_send, 8004)).start()
#		Thread(target = send_thread_at_will, args=(msg_to_send, 8007)).start()
#--------------------------------------------------------------------------------------------------
thread.start_new_thread(process_1, ())
thread.start_new_thread(process_1_listen, ())
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
