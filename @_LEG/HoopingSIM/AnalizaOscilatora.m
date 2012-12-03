clc;
clear all;


H = 4;%
m=1;%masa
k=800;%opruga
g=9.81;
c=8;

v0=sqrt(2*abs(g)*H)%preko odnosa pocencijalne i kin energije. MOra biti abs(g) jer je 
%Tc s gusenjem
wd = 1/(2*m)*sqrt(4*k*m-c*c);
Td = pi/wd
Tf = 2*v0*exp(-c*pi/(2*m*wd))/g

%ova jednadba je provjerena i dobra je
% t = [0:0.0001:5];
% y = ( (c*g-2*k*v0)/(2*k*wd)*sin(wd.*t)+m*g/k*cos(wd.*t)).*exp(-c/(2*m).*t)-m*g/k;
% 
% 
% plot(t,y)
% 
% kk = CrossingDetect(y',0);
% t1 = t(kk(1));
% PeriodSW1 = t1
% % 
% % t2 = t(kk(2));
% % t1 = t(kk(1));
% % PeriodSW2 = t2-t1
% % 
% % t2 = t(kk(3));
% % t1 = t(kk(2));
% % PeriodSW3 = t2-t1
% % 
% % t2 = t(kk(4));
% % t1 = t(kk(3));
% % PeriodSW4 = t2-t1




