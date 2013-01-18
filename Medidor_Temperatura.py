####################################################################################
#	ArduinoSerial.py
#	Autor: Willian.A.Mayan
#	Data: 09-12-2012
#	Vers~ao: 0.0.1
####################################################################################

#!/usr/bin/python
#-*-coding:utf-8-*-

#importar lib pyserial
import serial
#importar data e hora do sistema
from datetime import datetime


#Objetos utilizados para leitura da saida serial do arduino
ser = serial.Serial('/dev/ttyACM0',9600)
ser.flushInput();


#today = datetime.now()
#print today

while True:
	temperatura = ser.readline()
	print "Temperatura atual: "+temperatura
