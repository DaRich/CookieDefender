function main_servo_test

    clear all; close all; clc;
    
    a = arduino();
    s = servo(a, 'D4');
    
    clear s;
    s = servo(a, 'D4', 'MinPulseDuration', 700*10^-6,...
        'MaxPulseDuration', 2300*10^-6)
   
   for angle = 0:0.2:1
       writePosition(s, angle);
       current_pos = readPosition(s);
       current_pos = current_pos*180;
       fprintf('Current motor position is %d degrees\n', current_pos);
       pause(2);
   end
   
   clear s a
end
 
 