%Clear console and previous variables.
clear
clc

%User input for control height and the fluid density of the air.
hControl = input('Enter controlled-descent height (m):');
fprintf('\n');
fluidDens = input('Enter fluid density (kg/m^3):');
fprintf('\n');

%Constants for use in all iterations of the simulation.
mass = 15600;
diameter = 3.7;
maxThrust = 174850;
C = 1.0;
g = 9.8;
crossSection = pi * ((diameter/2)^2);

%Repeat the simluation 3 times with 3 different time increment sizes.
for i=0:1:2
    %Set time increment for the iteration of the simulation.
    dt = (10^-i);

    %Reset initial values for each iteration of the simulation.
    vel = -1500/3.6;
    alt = 10000;
    burnTimeRemaining = 60;
    flightTime = - dt;
    
    %Create empty arrays to hold data, counter to iterate through array indexes.
    counter = 0;
    accelData = [];
    altData = [];
    velData = [];
    timeData = [];

    while alt > 0        
        %Checks to see if rocket is at or below the set control height and if there is sufficient fuel.
        if burnTimeRemaining >= 0 && alt <= hControl
            %Activate thruster.
            Fthrust = maxThrust;
            %Deduct burn time from remaining burn time.
            burnTimeRemaining = burnTimeRemaining - dt;
        else
            %Turn thruster off.
            Fthrust = 0;
        end
        
        %Calculate the individual forces.
        Fgrav = -g * mass;
        Fdrag = -(vel/abs(vel))* 0.5 * C * fluidDens * crossSection * (vel^2);
        
        %Update position, acceleration, and speed based on calculated forces.
        accel = (Fgrav + Fdrag + Fthrust)/mass;
        alt = alt + vel*dt;
        vel = vel + accel*dt;
        
        %Increment the time elapsed for the flight.
        flightTime = flightTime + dt;
        
        %Increment array index counter.
        counter = counter + 1;
        
        %Store calculated data.
        accelData(counter) = accel;
        altData(counter) = alt;
        velData(counter) = vel;
        timeData(counter) = flightTime;
    end
    
    %Print out required information.
    fprintf("dt = %0.2f s, Total time = %0.0f s, Position = %0.0f m\n", dt, flightTime, alt);
end

%Print out required information for final iteration.
fprintf("landing speed: %0.0f km/h\n", abs(vel*3.6));
if abs(vel*3.6) <= 10
    fprintf("Successful landing\n");
else
    fprintf("Non-successful landing\n");
end