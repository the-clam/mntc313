clc
clear all

height = input('Enter controlled-descent height (m):');
fprintf('\n');
rho = input('Enter fluid density (kg/m^3):');
fprintf('\n');

if rho < 0
    fprintf('Fluid density must be positive\n');
    return;
end

C=0.7;
r=3.7 /2;
A=pi*r^2;

mass = 15600;
P0 = 174850; 
tGas = 60;
dt = [1 0.1 0.01];
speedLimit = 10;
g = 9.8;

for i = 1:numel(dt) %Run outer loop for different dt values
    x = 10000; %Initialize kinematic variables
    v = -1500/3.6;
    t = 0;
    a = 0;
    j = 1;
    tG=0;
    indHeight=0;
    
    while x >= 0 %Run inner loop until vehicle has stopped
        t = (j-1)*dt(i); %Calculate time

        if (x <= height)
            indHeight=1; %indicator that height was reached
        end
        if (indHeight == 1)&&(tG<=tGas) %Force from pressing gas
            P = P0;
            tG=tG+dt(i);
        else
            P = 0;
        end

        a = - g - 0.5*rho*A*v*v/mass*sign(v) + P/mass; %Acceleration from Newton's 2nd law
        x = x + v*dt(i);
        v = v + a*dt(i);

        aOut(j,i) = a; %Store variables, update counter
        xOut(j,i) = x;
        vOut(j,i) = abs(v);
        tOut(j,i) = t;
        j = j + 1;
    end
    timeTotal(i) = tOut(end, i); %Extract total times and distances
    position(i) = xOut(end, i);
    fprintf('dt = %0.2f s, Total time = %0.0f s, Position = %0.0f m\n', dt(i),timeTotal(i),position(i));
end

landingSpeed = 3.6*(vOut(end, end)); %Calculate max speed, compare to limit
fprintf('landing speed: %0.0f km/h\n', landingSpeed);

if landingSpeed > speedLimit
    fprintf('Non-successful landing\n');
else
    fprintf('Successful landing\n');
end
% 
% %% Plots of x, v, a - not required for assignment
% subplot(3,1,1)
% plot(tOut(:,3), xOut(:, 3))
% ylabel('Distance [m]')
% subplot(3,1,2)
% plot(tOut(:,3), vOut(:, 3))
% ylabel('Velocity [m/s]')
% subplot(3,1,3)
% plot(tOut(:,3), aOut(:, 3))
% ylabel('Acceleration [m/s^2]')
% xlabel('Time [s]')

 
