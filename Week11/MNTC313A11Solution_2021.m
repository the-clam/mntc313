clc
clear all 
a = input('Enter a:'); %%User input
fprintf('\n');
b = input('Enter b:');
fprintf('\n');

h = 500;
% if a < 0 || b < 0 %%Special cases, not necessary for assignment
%     fprintf('ERROR: Both limits must be non-negative\n');
%     return; %%Integral would evaluate, but for a real world application, we want a positive integral
% end
% 
% if b <= a
%     fprintf('ERROR: Upper limit must be greater than lower limit\n');
%     return;
% end
% 
% if b > h
%     fprintf('ERROR: Limit cannot be greater than building height\n');
%     return; 
% end

N = [10 100 1000 10000 100000]; %Array of different N values to be used

f = @(x) 1.8.^(0.045.*x)-1; %function handle
trueVal = quadgk(f, a, b); %Calculate true value with Gauss Quadrature
fprintf('True value: %0.0f N\n',trueVal);

dx = (b-a)./N; %Calculate array of dx values to be used
Y = zeros(1,numel(N));
for j = 1:numel(N)
    xSet = linspace(a, b, N(j)); %Generate x values
    fSet = 1.8.^(0.045.*xSet) - 1; %Generate function values
    Y(j) = sum(fSet.*dx(j)); %Calculate rectangle area and sum all the areas
    error(j) = 100*abs((Y(j)-trueVal)/trueVal);%Relative error
    fprintf('N = %d, F = %0.0f N, Error %% = %0.2f\n',N(j),Y(j),error(j));
end

a1 = h - 50; %Same procedure from above, except for a different interval.
b1 = h; %Different intervals for different versions
dx1 = (b1-a1)./N(5); %Use N(4) for version C
force = 0;
xSet1 = linspace(a1, b1, N(5));
fSet1 = 1.8.^(0.045.*xSet1) - 1;
force = sum(fSet1*dx1);

area = (b1-a1)*(50);
pressure = force/area/10^3; %Pressure calculation
fprintf('Average pressure between %d and %d m: %0.1f kPa\n', a1, b1, pressure);

