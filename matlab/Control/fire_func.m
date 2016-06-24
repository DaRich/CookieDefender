function fire_func

    clear all; close all; clc;

    a = arduino();
    s = servo(a, 'D4');

    clear s;
    s = servo(a, 'D4', 'MinPulseDuration', 700*10^-6,...
        'MaxPulseDuration', 2300*10^-6)

    str = 'i';
    recal(s);
    
    while ~strcmp(str,'d') 
        
        prompt = 'Increase or decrease? i/d [i]: ';
        str = input(prompt,'s');

        if strcmp(str,'i') 
            fire(s)
            pause(1)
            recal(s);     
        end
    
    end    
    
    clear s a

end

function recal(s)

    current_pos = readPosition(s);
    
    if current_pos > 0
        writePosition(s, 0);
    end

end

function roll(s)

    current_pos = readPosition(s);
    
    if current_pos > 0
        writePosition(s, 0);
    end

end

function fire(s)

    angle = .25;
    writePosition(s, angle);
    current_pos = readPosition(s);
    current_pos = current_pos*180;
    fprintf('FIRE!!! Current motor position is %d degrees\n', current_pos);

end



