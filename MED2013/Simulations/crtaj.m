%dimenzije tijela robota[m]
%body_dimmensions[3]={0.30,0.15,0.01};

%rep mase 3kg, dugacak 0.1m
clear all;
close all;

%TEST 1, mase 1 i 2 su jako male, ostale po kilu
load('logging_TEST1.txt');
gca1 = gca;% get handle to axes of figure
subplot(3,2,1);plot(logging_TEST1(:,1),logging_TEST1(:,4),'r','LineWidth',2);
hold on;
%title('Test 1');
h = ylabel('Test 1:$\left \| \vec{\omega} \right \|$');
set(h,'interpreter','latex')
xlabel('Time[s]');
grid;
subplot(3,2,2);
plot(logging_TEST1(:,1),logging_TEST1(:,2),'g','LineWidth',2);
hold on;
plot(logging_TEST1(:,1),logging_TEST1(:,3),'r','LineWidth',2);
h = legend('$Q_1$','$Q_2$');
set(h,'interpreter','latex')
grid;
h = ylabel('$deg[^{\circ}]$');
set(h,'interpreter','latex')
xlabel('Time[s]');
%title('Tail angles');
set(h,'interpreter','latex')

%TEST 2, mase 3 i 4 su jako male, ostale po kilu
load('logging_TEST2.txt');
subplot(3,2,3);plot(logging_TEST2(:,1),logging_TEST2(:,4),'r','LineWidth',2);
hold on;
%title('Test 2');
h = ylabel('Test 2:$\left \| \vec{\omega} \right \|$');
set(h,'interpreter','latex')
xlabel('Time[s]');
grid;
subplot(3,2,4);
plot(logging_TEST2(:,1),logging_TEST2(:,2),'g','LineWidth',2);
hold on;
plot(logging_TEST2(:,1),logging_TEST2(:,3),'r','LineWidth',2);
h = legend('$Q_1$','$Q_2$');
set(h,'interpreter','latex')
grid;
h = ylabel('$deg[^{\circ}]$');
set(h,'interpreter','latex')
xlabel('Time[s]');
%title('Tail angles');
set(h,'interpreter','latex')

% TEST 3, masa 4 mala, ostale po kilu
load('logging_TEST3.txt');
subplot(3,2,5);plot(logging_TEST3(:,1),logging_TEST3(:,4),'r','LineWidth',2);
hold on;
%title('Test 3');
h = ylabel('Test 3:$\left \| \vec{\omega} \right \|$');
set(h,'interpreter','latex')
xlabel('Time[s]');
grid;
subplot(3,2,6);
plot(logging_TEST3(:,1),logging_TEST3(:,2),'g','LineWidth',2);
hold on;
plot(logging_TEST3(:,1),logging_TEST3(:,3),'r','LineWidth',2);
h = legend('$Q_1$','$Q_2$');
set(h,'interpreter','latex')
grid;
h = ylabel('$deg[^{\circ}]$');
set(h,'interpreter','latex')
xlabel('Time[s]');
%title('Tail angles');
set(h,'interpreter','latex')

export_fig -transparent ODE_graph.pdf
