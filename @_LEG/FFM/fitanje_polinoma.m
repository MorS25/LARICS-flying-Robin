function [ p ] = fitanje_polinoma(x, y, x0,y0, n, P)
%FITANJE_POLINOMA Summary of this function goes here
%   Detailed explanation goes here
%   Inputs - x data vector
%          - y data vector
%          - n order of fitting polynomial 
%          - x0, y0 point which must be satisfied
%          - plot on = 1 
%   Outputs - polynomial coefficients
%

x = x(:); %reshape the data into a column vector
y = y(:);

% 'C' is the Vandermonde matrix for 'x'
V(:,n+1) = ones(length(x),1,class(x));
for j = n:-1:1
V(:,j) = x.*V(:,j+1);
end
C = V;

% 'd' is the vector of target values, 'y'.
d = y;

%%
% There are no inequality constraints in this case, i.e., 
A = [];
b = [];

%%
% We use linear equality constraints to force the curve to hit the required point. In
% this case, 'Aeq' is the Vandermoonde matrix for 'x0'
Aeq = x0.^(n:-1:0);
% and 'beq' is the value the curve should take at that point
beq = y0;

%% 
p = lsqlin( C, d, A, b, Aeq, beq );

%%
% We can then use POLYVAL to evaluate the fitted curve
yhat = polyval( p, x );

%%
if P==1
    % Plot original data
    plot(x,y,'.b-') 
    hold on
    % Plot point to go through
    plot(x0,y0,'gx','linewidth',6) 
    % Plot fitted data
    plot(x,yhat,'r','linewidth',2)
    grid on
    legend('Original data','Constraint point', 'Fitted curve')
    hold off
end
end

