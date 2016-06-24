import cv2
import numpy as np;

cap = cv2.VideoCapture(0)

while(1):
	_,frame = cap.read()
	#cv2.imshow('frame',frame)
	
	hsv = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
	
	low_blue = np.array([90,50,200])
	upper_blue = np.array([130,255,255])
	
	mask = cv2.inRange(hsv,low_blue,upper_blue)
	
	res = cv2.bitwise_and(frame,frame,mask = mask)


        #im_w_Key = cv2.drawKeypoints(res,keys,np.array([]),(0,0,255),cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
        
        
	cv2.imshow('res',res)
	
	
	k = cv2.waitKey(1) & 0xFF
	if k == 27:
		break
	
cv2.destroyAllWindows()
