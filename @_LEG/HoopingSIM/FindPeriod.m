clc
H = 3;%skacem s vidine od 3 metra iznad L0(3), sto je ukupno 6
l0=3;
m=1;%masa
k=800;%opruga
g=9.81;
c=1;

v0=sqrt(2*abs(g)*H);%preko odnosa pocencijalne i kin energije. MOra biti abs(g) jer je 
%Tc s gusenjem
wd = 1/(2*m)*sqrt(4*k*m-c*c);
Tc_A = pi/wd
Tf_A = 2*v0*exp(-c*pi/(2*m*wd))/g
Total_A = Tc_A + Tf_A

wd = 2*pi/Total_A




