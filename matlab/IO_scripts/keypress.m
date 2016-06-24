% f = figure;
% 
% increasing = 0;
% 
% while 1
%     
%     if w == 0
%         disp('Increasing')
%         increasing = increasing + 1;
%     end
%     w = waitforbuttonpress;
% end

clear all; close all; clc;

increasing = 0;

while 1
    prompt = 'Increase or decrease? i/d [i]: ';
    str = input(prompt,'s');
    
    if strcmp(str,'i') 
        increasing = increasing+1      
    end
    
    if strcmp(str,'d') 
        increasing = increasing-1     
    end
    
end    
    