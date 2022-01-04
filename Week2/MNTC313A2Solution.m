clear all
clc

phoneUnit = 0.0183;
batteryUnit = 0.0095;

prompt = 'Enter length, width, depth and radius: ';
data = input(prompt, 's');
data = sscanf(data, '%f,');
pLen = data(1,:);
pWid = data(2,:);
pDep = data(3,:);
pRad = data(4,:);

face = (pLen-2*pRad)*(pWid-2*pRad)+2*(pLen-2*pRad)*(pRad)+2*(pWid-2*pRad)*(pRad)+pi*pRad*pRad;
facePerimeter = 2*(pLen-2*pRad) + 2*(pWid-2*pRad)+2*pi*pRad;
border = pDep*facePerimeter;
phoneSurf = 2*face + border;

phoneVol = face*pDep;
phoneCost = phoneUnit * phoneVol;
batteryVol = phoneVol*0.45;
batteryCost = batteryUnit * batteryVol;

fprintf('iPhone surface area:\n%0.0f mm2\n', phoneSurf);
fprintf('iPhone volume:\n%0.0f mm3\n', phoneVol);
fprintf('iPhone material cost:\n$%0.0f\n', phoneCost); 
fprintf('battery cost:\n$%0.0f\n', batteryCost);