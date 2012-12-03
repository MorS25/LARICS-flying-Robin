clc;
clear all;

TimeError = [];

%Ovdje testiramo sustav za promjene parametara H, k i C i kako se javljaju
%razlike u odnosu na simulacijski odziv - prati se greska odredivanja
%ukupnog vremena periode sustava

for i=1:50
H = 3;%skacem s vidine od 3 metra iznad L0(3), sto je ukupno 6
l0=3;
m=1;%masa
k=800;%opruga
g=9.81;
c=3;

v0=sqrt(2*abs(g)*H);%preko odnosa pocencijalne i kin energije. MOra biti abs(g) jer je 
%Tc s gusenjem
wd = 1/(2*m)*sqrt(4*k*m-c*c);
Tc_A = pi/wd
Tf_A = 2*v0*exp(-c*pi/(2*m*wd))/g
Total_A = Tc_A + Tf_A

set_param('HoppingLEG/SpringK','Value',num2str(k));
set_param('HoppingLEG/SpringC','Value',num2str(c));
set_param('HoppingLEG/Height','Value',num2str(H+l0));
sim('HoppingLEG');

y = output(:,1);
k = CrossingDetect(y,l0);
t2 = t(k(2));
t1 = t(k(1));
Tc = t2-t1

t2 = t(k(3));
t1 = t(k(2));
Tf = t2-t1

Total = Tc + Tf

PeriodError = (Total - Total_A)/Total*100;

TimeError = [TimeError PeriodError]
end

i = 1:50
plot(i,TimeError)



