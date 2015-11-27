%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%% Demo sprint review 3 %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Alexis Lothoré
% 26/11/2015
%
% To make it work : plug the Red Bear Lab Ble Nano, set the port in the
% Matlab Script (COMX), and ensure that the module only send 'X Y\r\n'.
% Finally, set Room Size with W & H.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
close all;
clear all;
clc;
delete(instrfindall) ;


figure ('Name', 'First bluetooth geolocation');
whitebg([0.5 0.8 0.5]);
axis square;
axis off;
W=7;
H=9;

s=serial('COM3');
fopen(s);
plotLocation(0, 0);

%Main loop : the code is wainting for "x y\r\n" on serial
while(1)
    while(s.BytesAvailable<2)
    end
    pos=fscanf(s, '%f %f');
    plotLocation(pos(1), pos(2));
    pause(0.01);
end
    