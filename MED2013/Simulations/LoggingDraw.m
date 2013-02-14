function [gca1 gca2]=LoggingDraw(logg)

figure;
gca1 = gca;% get handle to axes of figure
plot(logg(:,1),logg(:,4),'r','LineWidth',2);
title('Optimisation criteria');
h = ylabel('$\left \| \vec{\omega} \right \|$');
set(h,'interpreter','latex')
xlabel('Time[s]');
grid;
figure;
gca2 = gca;% get handle to axes of figure
plot(logg(:,1),logg(:,2),'g','LineWidth',2);
hold on;
plot(logg(:,1),logg(:,3),'r','LineWidth',2);
h = legend('$Q_1$','$Q_2$');
set(h,'interpreter','latex')
grid;
h = ylabel('$deg[^{\circ}]$');
set(h,'interpreter','latex')
xlabel('Time[s]');
title('Tail angles');
set(h,'interpreter','latex')

end