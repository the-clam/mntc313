clc
clear all
prompt = 'Input rock unit weight (kN/m3): ';
unitWeight = input(prompt);
prompt = 'Input number of depth values: ';
Nd = input(prompt);
prompt = 'Input first depth value (m): ';
firstDepth = input(prompt);
prompt = 'Input depth increment (m): ';
depthIncrement = input(prompt);
prompt = 'Input number of k values: ';
Nk = input(prompt);
prompt = 'Input first k value: ';
firstK = input(prompt);
prompt = 'Input k increment: ';
kIncrement = input(prompt);%User input prompts
%Note that using user input like this in MATLAB is not overly common
%This has been shown to mimic C/C++ user input

depthVals = firstDepth: depthIncrement:(firstDepth+(Nd-1)*depthIncrement);
kVals = firstK: kIncrement:(firstK+(Nk-1)*kIncrement);

stressV = unitWeight*depthVals; %Since multiplying by a constant, elementwise (.*) not needed
stressH = stressV'*kVals;
fprintf('Vertical stress values (kPa):\n'); %"Horizontal stress values (kPa)" for Version B
fprintf('%0.0f\n', stressV); %stressH for Version B.

fileMatrix = [depthVals' stressH]; %depthVals, stressV for Version B, stressH,
%Turns both row vectors into column vectors, then puts them into a matrix
writematrix(fileMatrix, 'outputFileA.txt'); %...B.txt for Version B.
%Write the matrix to a file, values are comma delimited by default
%Can also use dlmwrite