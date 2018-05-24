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
import datetime

f=open('config3.txt')
lines=f.readlines()

TCP_IP = lines[1].rstrip('\n')
TCP_PORT = lines[2]
BUFFER_SIZE = lines[5]
aString = 'i am server3'
my_server_id = 5003
central_server_id = lines[3]

Server_TCP_IP = '127.0.0.1'

#Max delay time in seconds
MAX = lines[20]
firstWord = 'a'
secondWord = 'a'
thirdWord = 1
Key = 1
Model = 0
Value = 1
#temp_msg_to_send = 
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
				msg_to_send = "cmn_server" + ' ' + q1[0][0] + ' ' + str(my_server_id) + ' ' + str(q1[0][3]) + ' ' + str(q1[0][4])
				#cmn_server secondWord my_server_id timedelay realtime
				s1.connect((Server_TCP_IP, int(q1[0][2])))
				s1.send(msg_to_send)
				s1.close()
				time.sleep(0.5)
				q1.pop(0)
				temp_len_q1 -= 1
				while True:
					if (temp_len_q1 > 0):
						if(q1[0][1] <= 0):
							msg_to_send = "cmn_server" + ' ' + q1[0][0] + ' ' + str(my_server_id) + ' ' + str(q1[0][3]) + ' ' + str(q1[0][4])
							s1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
							s1.connect((Server_TCP_IP, int(q1[0][2])))
							s1.send(msg_to_send)
							s1.close()
							time.sleep(0.5)
							q1.pop(0)
							temp_len_q1 -= 1
						else:
							break
					else:
						break			

def q2_thread():
	while True:
		time.sleep(1)
		temp_len_q2 = len(q2)
		if(temp_len_q2 > 0):
			for i in range(temp_len_q2):
				q2[i][1] -= 1
			if(q2[0][1] <= 0):
				s2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				msg_to_send = "cmn_server" + ' ' + q2[0][0] + ' ' + str(my_server_id) + ' ' + str(q2[0][3]) + ' ' + str(q2[0][4])
				s2.connect((Server_TCP_IP, int(q2[0][2])))
				s2.send(msg_to_send)
				s2.close()
				time.sleep(0.5)
				q2.pop(0)
				temp_len_q2 -= 1
				while True:
					if (temp_len_q2 > 0):
						if(q2[0][1] <= 0):
							msg_to_send = "cmn_server" + ' '
							msg_to_send = msg_to_send + q2[0][0] + ' ' + str(my_server_id) + ' ' + str(q2[0][3]) + ' '+ str(q2[0][4])
							s2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
							s2.connect((Server_TCP_IP, int(q2[0][2])))
							s2.send(msg_to_send)
							s2.close()
							time.sleep(0.5)
							q2.pop(0)
							temp_len_q2 -= 1
						else:
							break
					else:
						break			

def q3_thread():
	while True:
		time.sleep(1)
		temp_len_q3 = len(q3)
		if(temp_len_q3 > 0):
			for i in range(temp_len_q3):
				q3[i][1] -= 1
			if(q3[0][1] <= 0):
				s3 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				msg_to_send = "cmn_server" + ' ' + q3[0][0] + ' ' + str(my_server_id) + ' ' + str(q3[0][3]) + ' ' + str(q3[0][4])
				s3.connect((Server_TCP_IP, int(q3[0][2])))
				s3.send(msg_to_send)
				s3.close()
				time.sleep(0.5)
				q3.pop(0)
				temp_len_q3 -= 1
				while True:
					if (temp_len_q3 > 0):
						if(q3[0][1] <= 0):
							msg_to_send = "cmn_server" + ' ' + q3[0][0] + ' ' + str(my_server_id) + ' ' + str(q3[0][3]) + ' ' + str(q3[0][4])
							s3 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
							s3.connect((Server_TCP_IP, int(q3[0][2])))
							s3.send(msg_to_send)
							s3.close()
							time.sleep(0.5)
							q3.pop(0)
							temp_len_q3 -= 1
						else:
							break
					else:
						break			

def q4_thread():
	while True:
		time.sleep(1)
		temp_len_q4 = len(q4)
		if(temp_len_q4 > 0):
			for i in range(temp_len_q4):
				q4[i][1] -= 1
			if(q4[0][1] <= 0):
				s4 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				msg_to_send = "cmn_server" + ' ' + q4[0][0] + ' ' + str(my_server_id) + ' ' + str(q4[0][3]) + ' ' + str(q4[0][4])
				s4.connect((Server_TCP_IP, int(q4[0][2])))
				s4.send(msg_to_send)
				s4.close()
				time.sleep(0.5)
				q4.pop(0)
				temp_len_q4 -= 1
				while True:
					if (temp_len_q4 > 0):
						if(q4[0][1] <= 0):
							msg_to_send = "cmn_server" + ' ' + q4[0][0] + ' ' + str(my_server_id) + ' ' + str(q4[0][3]) + ' ' + str(q4[0][4])
							s4 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
							s4.connect((Server_TCP_IP, int(q4[0][2])))
							s4.send(msg_to_send)
							s4.close()
							time.sleep(0.5)
							q4.pop(0)
							temp_len_q4 -= 1
						else:
							break
					else:
						break			

def model3_thread():
	while True:
		time.sleep(1)
		temp_len_model3 = len(model3)
		if(temp_len_model3 > 0):
			for i in range(temp_len_model3):
				model3[i][1] -= 1
			if(model3[0][1] <= 0):
				s5 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				msg_to_send = model3[0][0]
				print "port here is ", model3[0][2]
				s5.connect((Server_TCP_IP, int(model3[0][2])))
				s5.send(msg_to_send)
				#ttt = s5.recv(50)	
				#print ttt
				s5.close()
				time.sleep(0.5)
				model3.pop(0)
				temp_len_model3 -= 1
				while True:
					if (temp_len_model3 > 0):
						if(model3[0][1] <= 0):
							msg_to_send = model3[0][0]
							s5 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
							s5.connect((Server_TCP_IP, int(model3[0][2])))
							s5.send(msg_to_send)
							#ttt = s5.recv(50)
							#print ttt
							s5.close()
							time.sleep(0.5)
							model3.pop(0)
							temp_len_model3 -= 1
						else:
							break
					else:
						break			

def model4_thread():
	while True:
		time.sleep(1)
		temp_len_model4 = len(model4)
		if(temp_len_model4 > 0):
			for i in range(temp_len_model4):
				model4[i][1] -= 1
			if(model4[0][1] <= 0):
				s6 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				msg_to_send = model4[0][0]
				s6.connect((Server_TCP_IP, int(model4[0][2])))
				s6.send(msg_to_send)
				#ttt = s6.recv(50)
				#print ttt
				s6.close()
				time.sleep(0.5)
				model4.pop(0)
				temp_len_model4 -= 1
				while True:
					if (temp_len_model4 > 0):
						if(model4[0][1] <= 0):
							msg_to_send = model4[0][0]
							s6 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
							s6.connect((Server_TCP_IP, int(model4[0][2])))
							s6.send(msg_to_send)
							#ttt = s6.recv(50)
							#print ttt
							s6.close()
							time.sleep(0.5)
							model4.pop(0)
							temp_len_model4 -= 1
						else:
							break
					else:
						break			

def get_model3_thread():
	while True:
		time.sleep(2)
		if(len(q3_get) > 0):
			time_delay = random.randint(0, int(MAX))
			s10 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			s10.connect((Server_TCP_IP, random.randint(5001, 5004)))
			temp_q3_msg = str(q3_get[0][0])
			time.sleep(time_delay)
			s10.send(temp_q3_msg)
			time1 = s10.recv(50)
			s10.close()
			print("ack in thread msg is ", time1)				
			q3_get.pop(0)

def get_model4_thread():
	while True:
		time.sleep(2)
		if(len(q4_get) > 1):
			random_server_get4a = random.randint(5001, 5004)
			random_server_get4b = random.randint(5001, 5004)
			while (random_server_get4b == random_server_get4a):
				random_server_get4b = random.randint(5001, 5004)	
			time_delay = random.randint(0, int(MAX))
			s11 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			s11.connect((Server_TCP_IP, random_server_get4a))
			temp_q4_msg = str(q4_get[0][0])
			time.sleep(time_delay)
			s11.send(temp_q4_msg)
			time1 = s11.recv(50)
			s11.close()
			q4_get.pop(0)

			time_delay = random.randint(0, int(MAX))
			s12 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			s12.connect((Server_TCP_IP, random_server_get4b))
			temp_q4_msg = str(q4_get[0][0])
			time.sleep(time_delay)
			s12.send(temp_q4_msg)
			time2 = s12.recv(50)
			s12.close()
			q4_get.pop(0)
			
			dat1 = time1.split(' ')
			dat2 = time2.split(' ')		
			
			if(dat1[1] > dat2[1]):
				print ("msg is ", dat1[0])
			else:
				print("msg is ", dat2[0])											



#initializing lists inside list where 1st element is the message and the 2nd element is the wait_time
q1 = []
q2 = []
q3 = []
q4 = []
model3 = []
model4 = []
key_val = {}			#dictionary where key and value are both integers	 
q3_get = []
q4_get = []

#defination of a thread to read a message
def get_msg():
	while True:
		aString = raw_input('')
		real_time = datetime.datetime.now().time()
		word = aString.split()
		word_len = len(word)
		global firstWord
		global Key
		global secondWord
		global thirdWord
		global Model
		global Value
		
		firstWord = word[0]
		wait_time = random.randint(0, int(MAX))			#pick a random number between 0 and MAX
		if firstWord=="Send":
			if (word_len >= 2):
				secondWord = word[1]
			else:
				print "insufficient input"
				return
			if (word_len >= 3):
				thirdWord = word[2]
			else:
				print "insufficient input"
				return	
			if (int(thirdWord) == 5001):
				q1.append([secondWord, wait_time, thirdWord, wait_time, real_time])	#secondWord is msg, wait_time is the random time delay
				print "Sent %s to %s, system time is %s" %(secondWord, thirdWord, datetime.datetime.now().time())
			elif (int(thirdWord) == 5002):
				q2.append([secondWord, wait_time, thirdWord, wait_time, real_time])	
				print "Sent %s to %s, system time is %s" %(secondWord, thirdWord, datetime.datetime.now().time())				
			elif (int(thirdWord) == 5003):
				q3.append([secondWord, wait_time, thirdWord, wait_time, real_time])
				print "Sent %s to %s, system time is %s" %(secondWord, thirdWord, datetime.datetime.now().time())				
			elif (int(thirdWord) == 5004):
				q4.append([secondWord, wait_time, thirdWord, wait_time, real_time])
				print "Sent %s to %s, system time is %s" %(secondWord, thirdWord, datetime.datetime.now().time())				
			else:
				print "wrong port number"
				return

		elif firstWord=="delete":
			if (word_len >= 2):
				Key = int(word[1])
				msg_to_send = "central_server" + ' ' + str(firstWord) + ' ' + str(Key) + ' ' + str(my_server_id) + ' ' + str(real_time)
				s0 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				s0.connect((Server_TCP_IP, int(central_server_id)))
				s0.send(msg_to_send)
				s0.close()			
			else:
				print "insufficient input"
				return
				
		elif firstWord=="get":
			if (word_len >= 3):
				Key = int(word[1])
				Model = int(word[2])
				if (Model == 1):
					msg_to_send = "central_server" + ' ' + "get" + ' ' + str(Key) + ' ' + str(my_server_id) + ' ' + str(real_time) + ' ' + str(Model)
					s0 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
					s0.connect((Server_TCP_IP, int(central_server_id)))
					s0.send(msg_to_send)
					t = s0.recv(4)
					s0.close()			
				elif (Model == 2):
					msg_to_send = "central_server" + ' ' + "get" + ' ' + str(Key) + ' ' + str(my_server_id) + ' ' + str(real_time) + ' ' + str(Model)
					s0 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
					s0.connect((Server_TCP_IP, int(central_server_id)))
					s0.send(msg_to_send)
					t = s0.recv(4)
					s0.close()			
				elif (Model == 3):
					global ack_temp_msg_to_send
					msg_to_send = "central_server" + ' ' + "get" + ' ' + str(Key) + ' ' + str(my_server_id) + ' ' + str(real_time) + ' ' + str(Model)											
					q3_get.append([msg_to_send])
					#thread.start_new_thread(get_model3_thread, ())
					
				elif (Model == 4):
					msg_to_send = "central_server" + ' ' + "get" + ' ' + str(Key) + ' ' + str(my_server_id) + ' ' + str(real_time) + ' ' + str(Model) 
					q4_get.append([msg_to_send])
					q4_get.append([msg_to_send])
#					print "both messages have been appended for model 4"
#					random_server_get4a = random.randint(5001, 5004)
#					random_server_get4b = random.randint(5001, 5004)
#					while (random_server_4b == random_server_4a):
#						random_server_4b = random.randint(5001, 5004)	
#					s7 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#					s7.connect((Server_TCP_IP, random_server_get4a))
#					s7.send(msg_to_send)
#					time1 = s7.recv(50)
#					s7.close()			
#					s7 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#					s7.connect((Server_TCP_IP, random_server_get4b))
#					s7.send(msg_to_send)
#					time2 = s7.recv(50)
#					s7.close()												
#					
#					dat1 = time1.split(' ')
#					dat2 = time2.split(' ')		
#					if(dat1[1] > dat2[1]):
#						print ("msg is ", dat1[0])
#					else:
#						print("msg is ", dat2[0])											
				
				else:
					print "incorrect Model no."
					print Model
				#	return			
			else:
				print "insufficient input"
				return

		elif firstWord=="insert":
			if (word_len >= 4):
				Key = int(word[1])
				Value = int(word[2])
				Model = int(word[3])
#				print "Model is ", Model				
				if ((Model == 1) or (Model == 2)):
					msg_to_send = "central_server" + ' ' + str(firstWord) + ' ' + str(Key) + ' ' + str(Value) + ' ' + str(my_server_id) + ' ' + str(real_time) + ' ' + str(Model)	
#					print "from send we ", msg_to_send	
					s0 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
					s0.connect((Server_TCP_IP, int(central_server_id)))
					s0.send(msg_to_send)
					s0.close()			
					
				elif (Model == 3):				
					msg_to_send = "central_server" + ' ' + str(firstWord) + ' ' + str(Key) + ' ' + str(Value) + ' ' + str(my_server_id) + ' ' + str(real_time) + ' ' + str(Model)
					random_server_3ina = random.randint(5001, 5004)
					random_server_3inb = random.randint(5001, 5004)
					while (random_server_3inb == random_server_3ina):
						random_server_3inb = random.randint(5001, 5004)										
					random_server_3inc = random.randint(5001, 5004)
					while ((random_server_3inc == random_server_3ina) or (random_server_3inc == random_server_3inb)):
						random_server_3inc = random.randint(5001, 5004)										
					random_server_3ind = random.randint(5001, 5004)
					while ((random_server_3ind == random_server_3ina) or (random_server_3ind == random_server_3inb) or (random_server_3ind == random_server_3inc)):
						random_server_3ind = random.randint(5001, 5004)								
					#we have all in order central_sever insert key value myserverid realtime model
					model3.append([msg_to_send, random.randint(0, int(MAX)), random_server_3ina])
					model3.append([msg_to_send, random.randint(0, int(MAX)), random_server_3inb])
					model3.append([msg_to_send, random.randint(0, int(MAX)), random_server_3inc])
					model3.append([msg_to_send, random.randint(0, int(MAX)), random_server_3ind])
					
				elif (Model == 4):
					msg_to_send = "central_server" + ' ' + str(firstWord) + ' ' + str(Key) + ' ' + str(Value) + ' ' + str(my_server_id)	+ ' ' + str(real_time) + ' ' + str(Model)
					random_server_4ina = random.randint(5001, 5004)
					random_server_4inb = random.randint(5001, 5004)
					while (random_server_4inb == random_server_4ina):
						random_server_4inb = random.randint(5001, 5004)										
					random_server_4inc = random.randint(5001, 5004)
					while ((random_server_4inc == random_server_4ina) or (random_server_4inc == random_server_4inb)):
						random_server_4inc = random.randint(5001, 5004)										
					random_server_4ind = random.randint(5001, 5004)
					while ((random_server_4ind == random_server_4ina) or (random_server_4ind == random_server_4inb) or (random_server_4ind == random_server_4inc)):
						random_server_4ind = random.randint(5001, 5004)								
					#we have all in order central_sever insert key value myserverid realtime model
					model4.append([msg_to_send, random.randint(0, int(MAX)), random_server_4ina])
					model4.append([msg_to_send, random.randint(0, int(MAX)), random_server_4inb])
					model4.append([msg_to_send, random.randint(0, int(MAX)), random_server_4inc])
					model4.append([msg_to_send, random.randint(0, int(MAX)), random_server_4ind])
				else:
					print "model number not allowed"

		elif firstWord=="update":
			if (word_len >= 4):
				Key = int(word[1])
				Value = int(word[2])
				Model = int(word[3])				
				if ((Model == 1) or (Model == 2)):
					msg_to_send = "central_server" + ' ' + str(firstWord) + ' ' + str(Key) + ' ' + str(Value) + ' ' + str(my_server_id)	+ ' ' + str(real_time) + ' ' + str(Model)				
					s0 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
					s0.connect((Server_TCP_IP, int(central_server_id)))
					s0.send(msg_to_send)
					s0.close()			
				elif (Model == 3):				
					msg_to_send = "central_server" + ' ' + str(firstWord) + ' ' + str(Key) + ' ' + str(Value) + ' ' + str(my_server_id) + ' ' + str(real_time) + ' ' + str(Model) 
					random_server_3upa = random.randint(5001, 5004)
					random_server_3upb = random.randint(5001, 5004)
					while (random_server_3upb == random_server_3upa):
						random_server_3upb = random.randint(5001, 5004)										
					random_server_3upc = random.randint(5001, 5004)
					while ((random_server_3upc == random_server_3upa) or (random_server_3upc == random_server_3upb)):
						random_server_3upc = random.randint(5001, 5004)										
					random_server_3upd = random.randint(5001, 5004)
					while ((random_server_3upd == random_server_3upa) or (random_server_3upd == random_server_3upb) or (random_server_3upd == random_server_3upc)):
						random_server_3upd = random.randint(5001, 5004)								
					#we have all in order update key value myserverid realtime model
					model3.append([msg_to_send, random.randint(0, int(MAX)), random_server_3upa])
					model3.append([msg_to_send, random.randint(0, int(MAX)), random_server_3upb])
					model3.append([msg_to_send, random.randint(0, int(MAX)), random_server_3upc])
					model3.append([msg_to_send, random.randint(0, int(MAX)), random_server_3upd])

				elif (Model == 4):
					msg_to_send = "central_server" + ' ' + str(firstWord) + ' ' + str(Key) + ' ' + str(Value) + ' ' + str(my_server_id) + ' ' + str(real_time) + ' ' + str(Model)	
					random_server_4upa = random.randint(5001, 5004)
					random_server_4upb = random.randint(5001, 5004)
					while (random_server_4upb == random_server_4upa):
						random_server_4upb = random.randint(5001, 5004)										
					random_server_4upc = random.randint(5001, 5004)
					while ((random_server_4upc == random_server_4upa) or (random_server_4upc == random_server_4upb)):
						random_server_4upc = random.randint(5001, 5004)										
					random_server_4upd = random.randint(5001, 5004)
					while ((random_server_4upd == random_server_4upa) or (random_server_4upd == random_server_4upb) or (random_server_4upd == random_server_4upc)):
						random_server_4upd = random.randint(5001, 5004)								
					#we have all in order central_server update key value myserverrrrid realtime model
					model4.append([msg_to_send, random.randint(0, int(MAX)), random_server_4upa])
					model4.append([msg_to_send, random.randint(0, int(MAX)), random_server_4upb])
					model4.append([msg_to_send, random.randint(0, int(MAX)), random_server_4upc])
					model4.append([msg_to_send, random.randint(0, int(MAX)), random_server_4upd])
				else:
					print "incorrect Model no."
					return							
			else:
				print "insufficient input"
				return
		elif (firstWord=="show-all"):
			print key_val

		elif (firstWord == "search"):
			Key = int(word[1])
			temp_msg = "central_server" + ' ' + str(firstWord) + ' ' + str(Key) + ' ' + str(my_server_id)
			for i in range (5001, 5005):
				s13 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				s13.connect((Server_TCP_IP, i))
				s13.send(temp_msg)
				search_msg = s13.recv(50)
				s13.close()
				if (search_msg == "yes"):
					print "server %s has the Key %s" %(i, Key)
				else:
					print "Server %s does not have the key %s" %(i, Key)
			
		else:
			print "No such command" 
						
#creating a thread
thread.start_new_thread(get_msg, ())
thread.start_new_thread(q1_thread, ())
thread.start_new_thread(q2_thread, ())
thread.start_new_thread(q3_thread, ())
thread.start_new_thread(q4_thread, ())
thread.start_new_thread(model3_thread, ())
thread.start_new_thread(model4_thread, ())
thread.start_new_thread(get_model3_thread, ())
thread.start_new_thread(get_model4_thread, ())

#this will do the listening part and print incoming messagaes
while 1:
	conn, addr = s.accept()
	data = conn.recv(int(BUFFER_SIZE))
	if data:
		data = data.rstrip('\n')
		print "packet data is ", data
		temp_recv_data = data.split(' ')
		msg_type = str(temp_recv_data[0])
		if (msg_type == "cmn_server"):					#cmn_server secondWord my_server_id timedelay realtime
			msg_data = str(temp_recv_data[1])
			if (len(temp_recv_data) > 2):
				sender_server_id = int(temp_recv_data[2])
			if (len(temp_recv_data) > 3):
				delay_recv_time = temp_recv_data[3]
			if (len(temp_recv_data) > 4):	
				time_stamp = temp_recv_data[4]
				
			if (sender_server_id == 5001):
				print "Received %s from server 1, Max delay is %s, system time is %s" %(msg_data, delay_recv_time, datetime.datetime.now().time())
			elif (sender_server_id == 5002):
				print "Received %s from server 2, Max delay is %s, system time is %s" %(msg_data, delay_recv_time, datetime.datetime.now().time())
			elif (sender_server_id == 5003):
				print "Received %s from server 3, Max delay is %s, system time is %s" %(msg_data, delay_recv_time, datetime.datetime.now().time())
			elif (sender_server_id == 5004):
				print "Received %s from server 4, Max delay is %s, system time is %s" %(msg_data, delay_recv_time, datetime.datetime.now().time())
			else:
				print "which server is sending packets??"
	
		elif (msg_type == "central_server"):	#central_sever insert key value myserverid realtime model
			if (len(temp_recv_data) > 1):
				msg_command = str(temp_recv_data[1])		
			if (len(temp_recv_data) > 2):	
				Key = temp_recv_data[2]
			if (len(temp_recv_data) > 3):	
				Value = int(temp_recv_data[3])
			if (len(temp_recv_data) > 4):	
				sender_server_id = temp_recv_data[4]
			if (len(temp_recv_data) > 5):	
				time_stamp = temp_recv_data[5]
			if (len(temp_recv_data) > 6):	
				Model = temp_recv_data[6]
			
			if (msg_command == "delete"):
				if Key in key_val.keys():
					del key_val[Key]
				print key_val
				#conn.send("delete command")	
			elif (msg_command == "get"):
				print key_val[Key]			
#				temp_dat = key_val[Key].split(' ')
#				time
				# msg time 
				#conn.send(key_val[Key])
				sent_server_id = temp_recv_data[3]
				time_stamp = temp_recv_data[4]
				if (len(temp_recv_data) > 5):
					Model = int(temp_recv_data[5])
				print "msg is ", temp_recv_data
#				if ((model == 1) or (model == 2))
				if ((Model == 3) or (Model == 4)):				
					model34_msg_to_send = key_val[Key]
					conn.send(model34_msg_to_send)
					print "read value has been sent"	
				print "came out of left"														
			elif (msg_command == "insert"):	
				Value = str(Value) + ' ' + str(time_stamp)
				key_val[Key] = Value
				print key_val
				#conn.send("insert command")
			elif (msg_command == "update"):
				Value = str(Value) + ' ' + str(time_stamp)
				key_val[Key] = Value
				print key_val
				#conn.send("update command")	
			elif (msg_command == "search"):
				Key = temp_recv_data[2]
				if Key in key_val:
					conn.send("yes")
				else:
					conn.send("no")				
			else:
				print "??? ???"							
		else:
			print "Where are these packets coming from"		
conn.close()
