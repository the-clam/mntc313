%Clear console screen and previous variables.
clear
clc

%User input for the limits of integration.
a = input('Enter a:');
fprintf('\n');
b = input('Enter b:');
fprintf('\n');

%Function to be integrated.
f = @(x) 1.8.^(0.045.*x)-1;

%Calculate and print true integral value.
trueVal = quadgk(f,a,b);
fprintf("True value: %0.0f N\n",trueVal);

%Calculate approximate integral values using different N values.
for i=1:1:5
    N = 10^i;
    independentVals = linspace(a,b,N);
    dependentVals = f(independentVals);
    dx = (b-a)/N;
    approxIntegration(i) = sum(dx*dependentVals);
    
    %Calculate error from true value using provided formula.
    error = abs((approxIntegration(i) - trueVal)/trueVal)*100;
    
    %Print out calculated approximation.
    fprintf("N = %d, F = %0.0f N, Error %% = %0.2f\n", N, approxIntegration(i), error);
end

%Calculate average pressure using N = 10000.
a = 450;
b = 500;
N = 10000;
independentVals = linspace(a,b,N);
dependentVals = f(independentVals);
dx = (b-a)/N;

%Average force (using N = 10000) between 450-500m, divided by surface area to get pressure.
%Divided by 1000 to convert to kilopascals.
avgPress = (sum(dx*dependentVals)/((b-a)*50))/1000;

%Print out average pressure.
fprintf("Average pressure between 450 and 500 m: %0.1f kPa\n", avgPress);