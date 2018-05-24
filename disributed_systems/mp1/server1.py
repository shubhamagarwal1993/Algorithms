#!/usr/bin/env python

import socket
import sys
import thread
import threading
import time
import readline
import io
import random
import re
#from thread import *
#from threading import Thread
#from time import sleep

f=open('config1.txt')
lines=f.readlines()

TCP_IP = lines[1].rstrip('\n')
TCP_PORT = lines[2]
BUFFER_SIZE = lines[5]
aString = 'i am server1'
my_server_id = 1

Server_TCP_IP = '127.0.0.1'

#Max delay time in seconds
MAX = lines[20]
firstWord = 'a'
secondWord = 'a'
thirdWord = 1

#trying to implement FIFO
send_packet_no = 0
recv_packet_no = 0
recv_buffer = { recv_packet_no: secondWord };

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, int(TCP_PORT)))
s.listen(1)

def wait_thread():
	local=secondWord
	print_local = local.split()
	print_local = print_local[0]
	wait_time = random.randint(0, int(MAX))			#pick a random number between 0 and MAX
	s1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s1.connect((Server_TCP_IP, int(thirdWord)))
	print "Sent %s to %s, system time is" %(print_local, thirdWord)
	time.sleep(wait_time)							#delay for MAX seconds
	s1.send(local)
	s1.close()


#defination of a thread to read a message
def get_msg():
	while True:
		aString = raw_input('')
		word = aString.split()
		global firstWord
		firstWord = word[0]
		if firstWord=="Send":
			temp_secondWord = word[1]
			temp_secondWord = temp_secondWord.rstrip('\n')
			global send_packet_no
			send_packet_no = send_packet_no+1
			temp_secondWord = temp_secondWord + " "
			temp_secondWord = temp_secondWord + str(send_packet_no)
			temp_secondWord = temp_secondWord + " "
			temp_secondWord = temp_secondWord + str(my_server_id)
			global secondWord
			secondWord = str(temp_secondWord)
			secondWord = secondWord.rstrip('\n')			
			global thirdWord
			thirdWord = word[2]
			thread.start_new_thread(wait_thread, ())

#defination of thread to send a message to a specified address and port
def print_msg():
	while True:
		aString == raw_input('')
		#print aString
		s1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		s1.connect((Server2_TCP_IP, Server2_TCP_PORT))
		s1.send(aString)
		s1.close()

				
#creating a thread
thread.start_new_thread(get_msg, ())
#thread1.start_new_thread(print_msg, ())

#threads = []
#t = threading.Thread(target=print_msg)
#t.start()

#thread.start_new_thread(print_msg, ())
#t1 = threading.Thread(target=get_msg)
#threads.append(t1)
#t1.start()



#this will do the listening part and print incoming messagaes
while 1:
	conn, addr = s.accept()
	data = conn.recv(int(BUFFER_SIZE))
	if data:
		data = data.rstrip('\n')
		temp_data = data.split(' ')
		recv_packet_no = temp_data[1]
		data = temp_data[0]
		server_id = temp_data[2]
		print "Received %s from %s, Max delay is , system time is" % (data, addr)
conn.close()

# part 2
# implement a Key-Value storage system
# each server may potentially store the value for each key in the shared datastore. Use positive integers as Key and Value both.
# 
