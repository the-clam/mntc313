clc
clear all

g=9.81;
pi=3.14;
prompt = 'Enter initial height, tank radius, pipe radius and final time: ';
data = input(prompt, 's');
data = sscanf(data, '%f');

initialHeight=data(1,:);
tankRad=data(2,:);
pipeRad=data(3,:);
finalT=data(4,:);

pipeSurf = pipeRad^2*pi;
tankSurf = tankRad^2*pi;

initialVol = initialHeight*tankSurf;
currentVol = initialVol;
currentHeight = initialHeight;


VelSum=0;
for t = 0:1:finalT
    Vel = 0.5*sqrt(2*g*currentHeight);
    VelSum=VelSum+Vel;
    Q = Vel*pipeSurf;
    deltaVol=Q*1;
    currentVol=currentVol-deltaVol;
    currentHeight=currentVol/tankSurf;

    if (t == 1800)
        heightHalfH = currentHeight;
    end
    
end

avgVel = VelSum / finalT;

fprintf("Average velocity value: %0.2f m/s\n", avgVel);
fprintf("Height value after 30 min: %0.2f m\n", heightHalfH);
fprintf("Height value after %d seconds: %0.2f m\n", finalT, currentHeight);

if (currentHeight <= 0.5*initialHeight)
    fprintf("Tank half drained\n");
else
    fprintf("Tank still not half drained\n");
end