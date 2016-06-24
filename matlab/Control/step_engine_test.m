clear all; close all; clc;

%a = arduino('COM3', 'Uno', 'Libraries', 'Adafruit\MotorShieldV2');
a = arduino()
dev = addon(a,'Adafruit\MotorshieldV2')
%dev = addon(a,'Adafruit\MotorshieldV2','i2caddress',...
%    '0x61', 'pwmfrequency',1200)

%addrs = scanI2CBus(a,0)

%Using port 1 of the shield servo ports
%s = servo(shield, 1)

sm = stepper(dev, 1,200,'RPM',10)

%sm = stepper(dev, 2, 200)

fprintf('Communication online...');

sm.RPM = 10;
move(sm, 200);
pause(2);
move(sm, -200);
release(sm);

fprintf('Closing...');

clear s dcm sm shield a

