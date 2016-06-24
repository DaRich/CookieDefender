a = arduino('COM3', 'Uno')%, 'Libraries', 'Adafruit\MotorShieldV2')
%shield = addon(a, 'Adafruit/MotorShieldV2')

shield = addon(a,'Adafruit\Motorshield') %'Adafruit\MotorshieldV2')%, 'i2caddress', '0x61'); %sets the I2C address to 97 or 0x61.

sm = stepper(shield,2,200,'RPM',10,'stepType','Single')

while 1
move(sm, 10)
pause(5);
end
clear all;