function main_fire_test

    clear all; close all; clc;

    a = arduino();
    s = servo(a, 'D4');

    clear s;
    s = servo(a, 'D4', 'MinPulseDuration', 700*10^-6,...
        'MaxPulseDuration', 2300*10^-6)

    range = 1;
    current_pos = readPosition(s)
    
    if current_pos > 0
        writePosition(s, 0);
    end

    angle = .25;
    
    pause(1)
    fire(s,angle)
    pause(1)
    writePosition(s, 0);
    clear s a

end

function fire(s,angle)

    %for angle = 0:0.1:1
        writePosition(s, angle);
        %writePosition(s, .1);
        current_pos = readPosition(s);
        current_pos = current_pos*180;
        fprintf('Current motor position is %d degrees\n', current_pos);
        %pause(2);
    %end

end

