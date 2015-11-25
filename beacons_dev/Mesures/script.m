clear all;
close all;
clc;
delete(instrfindall) ;

%%Variables � configurer
duree_s=10;
periode_adv_s=0.01;

%%Cr�ation et ouverture de la liaison s�rie
s1=serial('COM4', 'Baudrate', 9600);
fopen(s1);

%On attend un nombre suffisamment �lev� de donn�es
currentindex=1;
rssi=1;
while currentindex<1000


%On lit les donn�es dans le buffer
    nbdata=s1.bytesAvailable;
    if(nbdata>0)
        tampon=fscanf(s1, '%d');
        rssi=[rssi; tampon];
        currentindex=currentindex+nbdata
    end
end

taille=size(rssi);
fenetre=200;
for i=fenetre:taille(1)
    moy(i)=mean(rssi(i-fenetre+1:i));
end
    
fclose(s1);
figure('name', 'Relev� de rssi');    
plot(rssi, 'b.')
hold on
plot(moy, 'r');
choice=input('Filename to save data : ', 's');
save(choice, 'rssi')

    