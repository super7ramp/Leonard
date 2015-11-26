%Demo sprint review 33
close all;
clear all;
clc;
delete(instrfindall) ;


figure ('Name', 'First bluetooth geolocation');
whitebg([0.5 0.8 0.5])
axis square
axis off

s=serial('COM3');
fopen(s);

%Main loop : the code is wainting for "x y\r\n" on serial
while(1)
    while(s.BytesAvailable<2)
    end
    pos=fscanf(s, '%f %f');
    plotLocation(pos(1), pos(2));
    pause(0.01);
end
    