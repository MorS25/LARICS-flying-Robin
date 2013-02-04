%dimenzije tijela robota[m]
%body_dimmensions[3]={0.30,0.15,0.01};

%TEST 1, mase 1 i 2 su jako male, ostale po kilu
%rep mase 3kg, dugacak 0.1m

load('logging_TEST1.txt');
figure;
plot(logging(:,1),logging(:,4),'r','LineWidth',2);
title('Optimisation criteria');
h = ylabel('$\left \| \vec{\omega} \right \|$');
set(h,'interpreter','latex')
xlabel('Time[s]');
grid;


figure;
plot(logging(:,1),logging(:,2),'g','LineWidth',2);
hold on;
plot(logging(:,1),logging(:,3),'r','LineWidth',2);
h = legend('$Q_1$','$Q_2$');
set(h,'interpreter','latex')
grid;
h = ylabel('$deg[^{\circ}]$');
set(h,'interpreter','latex')
xlabel('Time[s]');
title('Tail angles');
set(h,'interpreter','latex')

