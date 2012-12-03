%%ovo gleda generalno minimume
clc;
y = output(:,1);
% k = find( diff( sign( diff([0; y; 0]) ) ) > 0 );
% PeriodTotal = t(k(2))-t(k(1))
% 
%%gledam na visini l0, veci je Tsw, manji Tst...iako ovisi o opruzi
l0=3;
k = CrossingDetect(y,l0);
t2 = t(k(4));
t1 = t(k(3));
PeriodSW1 = t2-t1
t2 = t(k(3));
t1 = t(k(2));
PeriodSW2 = t2-t1

t2 = t(k(4));
t1 = t(k(2));
PeriodUku = t2-t1

