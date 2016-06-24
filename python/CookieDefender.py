import cv2
import json
from random import randint
import requests
import serial
import struct
import time
import threading

url = 'https://api.projectoxford.ai/vision/v1.0/describe'
headers = {
   'Content-Type': 'application/octet-stream',
   'Ocp-Apim-Subscription-Key': 'f4a3ee6030b04380ae3779ad28ea67d3'
}
dataStruct = struct.Struct( 'B' );
ser = serial.Serial( '/dev/ttyS0' )
ser.baudrate = 9600

def findBlueTeddy():
	cap = cv2.VideoCapture( 0 )
	_, image = cap.read()
	cv2.imshow( 'image', image )
	_, data = cv2.imencode( '.jpg', image )	
	response = requests.post( url, data=bytearray( data ), headers=headers )
	data = json.loads( response.text )
	text = data['description']['captions'][0]['text']
	print 'Found in image:', text
	if 'blue teddy' in text:
		ser.write( dataStruct.pack( 5 ) )
	threading.Timer( 5, findBlueTeddy ).start()

findBlueTeddy()
while( 1 ):
	ser.write( dataStruct.pack( randint( 1, 4 ) ) )
	time.sleep( 1 )
	
ser.close()
cv2.destroyAllWindows()
