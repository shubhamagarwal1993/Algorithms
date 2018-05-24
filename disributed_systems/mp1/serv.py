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

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, int(TCP_PORT)))
s.listen(1)

def q1_thread():
	while True:
		time.sleep(1)
		temp_len_q1 = len(q1)
		if(temp_len_q1 > 0):
			for i in range(temp_len_q1):
				q1[i][1] -= 1
			if(q1[0][1] <= 0):
				s1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				print "the port to send the msg to is ", q1[0][2] 
				msg_to_send = q1[0][0]
				msg_to_send = msg_to_send + ' '
				msg_to_send = msg_to_send + str(q1[0][2])
				msg_to_send = msg_to_send + ' '
				msg_to_send = msg_to_send + str(q1[0][3]) 
				msg_to_send = msg_to_send + ' ' 								
				s1.connect((Server_TCP_IP, int(q1[0][2])))
				s1.send(msg_to_send)
				s1.close()
				time.sleep(0.5)
				q1.pop(0)
				temp_len_q1 -= 1
				while True:
					if (temp_len_q1 > 0):
						if(q1[0][1] <= 0):
							msg_to_send = q1[0][0]
							msg_to_send = msg_to_send + ' '
							msg_to_send = msg_to_send + str(q1[0][2])
							msg_to_send = msg_to_send + ' '
							msg_to_send = msg_to_send + str(q1[0][3]) 
							msg_to_send = msg_to_send + ' '
							s1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
							s1.connect((Server_TCP_IP, int(q1[0][2])))
							s1.send(msg_to_send)
							s1.close()
							time.sleep(0.5)
							q1.pop(0)
							temp_len_q1 -= 1
						else:
							print "leaving while loop"
							break
					else:
						print "dssdsd"
						break			
				print "came out of loop"

def q2_thread():
	while True:
		time.sleep(1)
		temp_len_q2 = len(q2)
		if(temp_len_q2 > 0):
			for i in range(temp_len_q2):
				q2[i][1] -= 1
			if(q2[0][1] <= 0):
				s2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				print "the port to send the msg to is ", q2[0][2] 
				s2.connect((Server_TCP_IP, int(q2[0][2])))
				s2.send(q2[0][0])
				q2.pop(0)
				temp_len_q2 -= 1
				while True:
					if (temp_len_q2 > 0):
						if(q2[0][1] <= 0):
							s2.send(q2[0])
							q2.pop(0)
						else:
							break	
				s2.close()

def q3_thread():
	while True:
		time.sleep(1)
		temp_len_q3 = len(q3)
		if(temp_len_q3 > 0):
			for i in range(temp_len_q3):
				q3[i][1] -= 1
			if(q3[0][1] <= 0):
				s3 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				s3.connect((Server_TCP_IP, int(q3[0][2])))
				s3.send(q3[0][0])
				q3.pop(0)
				temp_len_q3 -= 1
				while True:
					if (temp_len_q3 > 0):
						if(q3[0][1] <= 0):
							s3.send(q3[0])
							q3.pop(0)
						else:
							break	
				s3.close()
				
def q4_thread():
	while True:
		time.sleep(1)
		temp_len_q4 = len(q4)
		if(temp_len_q4 > 0):
			for i in range(temp_len_q4):
				q4[i][1] -= 1
			if(q4[0][1] <= 0):
				s4 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				s4.connect((Server_TCP_IP, int(q4[0][2])))
				s4.send(q4[0][0])
				q4.pop(0)
				temp_len_q4 -= 1
				while True:
					if (temp_len_q4 > 0):
						if(q4[0][1] <= 0):
							s4.send(q4[0])
							q4.pop(0)
						else:
							break	
				s4.close()

#initializing lists inside list where 1st element is the message and the 2nd element is the wait_time
q1 = []
q2 = []
q3 = []
q4 = [] 

#defination of a thread to read a message
def get_msg():
	while True:
		aString = raw_input('')
		word = aString.split()
		global firstWord
		firstWord = word[0]
		if firstWord=="Send":
			global secondWord
			secondWord = word[1]
			global thirdWord
			thirdWord = word[2]
			wait_time = random.randint(0, int(MAX))			#pick a random number between 0 and MAX
			#secondWord = secondWord + ' '
			#secondWord = secondWord + thirdWord
			#secondWord = secondWord + ' '
			#secondWord = secondWord + str(wait_time) 
			if (int(thirdWord) == 5001):
				q1.append([secondWord, wait_time, thirdWord, wait_time])
				print "have put to list"
			elif (int(thirdWord) == 5002):
				q2.append([secondWord, wait_time, thirdWord, wait_time])
			elif (int(thirdWord) == 5003):
				q3.append([secondWord, wait_time, thirdWord, wait_time])
			elif (int(thirdWord) == 5004):
				q4.append([secondWord, wait_time, thirdWord, wait_time])
			else:
				print "wrong port number"
				return
				
#creating a thread
thread.start_new_thread(get_msg, ())
thread.start_new_thread(q1_thread, ())
thread.start_new_thread(q2_thread, ())
thread.start_new_thread(q3_thread, ())
thread.start_new_thread(q4_thread, ())

#this will do the listening part and print incoming messagaes
while 1:
	conn, addr = s.accept()
	data = conn.recv(int(BUFFER_SIZE))
	if data:
		data = data.rstrip('\n')
		temp_recv_data = data.split(' ')
		msg_data = temp_recv_data[0]
		server_id = int(temp_recv_data[1])
		delay_recv_time = int(temp_recv_data[2])
		if (server_id == 5001):
			print "Received %s from server 1, Max delay is %s, system time is" % (msg_data, delay_recv_time)
		elif (server_id == 5002):
			print "Received %s from server 2, Max delay is %s, system time is" % (msg_data, delay_recv_time)
		elif (server_id == 5003):
			print "Received %s from server 3, Max delay is %s, system time is" % (msg_data, delay_recv_time)
		elif (server_id == 5004):
			print "Received %s from server 4, Max delay is %s, system time is" % (msg_data, delay_recv_time)
		else:
			print "Where are these packets coming from"		
conn.close()
