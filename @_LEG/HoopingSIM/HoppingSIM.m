%SIMUATION OF HOPPING



function HoppingSIM

global  l_0; 
global  h_init; % krecem s visine 2 metra
global  trajectoryY;
global  trajectorydY;
global  globalTime;

clc;

l_0 = 1;%opruga je dugacka 1 metar
h_init=2; % krecem s visine 2 metra
brojOdbijanja = 5;
trajectoryY = [];
trajectorydY = [];
globalTime = [];

    for i=1:brojOdbijanja
       %prvo simuliram fazu leta
        [y,y_dot,t] =flight_stage_1(h_init,0);
        trajectoryY=[trajectoryY y];
        trajectoryY=[trajectorydY y_dot];
        if(length(globalTime)>0)  
            globalTime = [globalTime t+globalTime(length(globalTime))]
        else
            globalTime = t;
        end

    end
        plot(globalTime,trajectoryY);
end
%% flight_stage_1
function [y,y_dot,t]= flight_stage_1(y, y_dot)
    % Function flight_stage_1 generates the motion for the fist parabolic flight
    % path.

    % INTIAL CONDITIONS:
    z0 = [y y_dot];

    tspan = [0 10]; %time interval of integration

    % Set error tolerance and use event detection:
    error = 1e-6; 
    options = odeset('abstol', error, 'reltol',error,'events', @stopevent1);

    % SOLVE:
    [t zarray] = ode113(@rhs1,tspan, z0, options);
    % Each row of zarray is the state z at one time.

    % UNPACK zarray (the solution)
    y= zarray(:,1);
    y_dot= zarray(:,2);
    t = t;
end

function [value, isterminal, dir] = stopevent1(t,q_let)

    global  l_0;
    % UNPACK z:
    y= q_let(1)
    y_dot= q_let(2);

    % If the following event happens, IE= 2, and FAIL
    value(2)      = y-l_0;                % OR stop integrating when y= 0
    isterminal(2) = 1;              % 1 means stop
    dir(2)        = -1;             % -1 for decreasing, +1 for increasing, 0 for any which way.

end



function y_double_dot = rhs1(t,q_let)
    % UNPACK z:
    y= q_let(1); 
    y_dot= q_let(2);

    % The equations of motion:
    g=9.81;
    y_dot2= y_dot;
    y_double_dot= -g;
        
    % Pack back up:
    y_double_dot = [y_dot2 y_double_dot]';  % Has to be a column vector
end
