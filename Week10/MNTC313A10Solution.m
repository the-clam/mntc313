%A10 Solution
%Note that sorting algorithm can also be used; however MATLAB has built in
%functions for this
clc
clear all

filename = 'goldDataA.txt';
dataRead = dlmread(filename, '\t'); %Read data delimited by tab characters

sampleID = dataRead(:,1); %create individual columns for each property
sampleLength = dataRead(:,2);
sampleRadius = dataRead(:,3);
sampleDensity = dataRead(:,4);
sampleGoldConc = dataRead(:,5);
sampleSulfConc = dataRead(:,6);
sampleArsConc = dataRead(:,7);

goldCutoff = 1; %define cutoff grade
sulfCutoff = 5;
arsCutoff = 1;

sampleGoldMass = sampleGoldConc.*(sampleLength.*sampleDensity.*pi.*sampleRadius.^2);
sampleSulfMass = sampleSulfConc.*(sampleLength.*sampleDensity.*pi.*sampleRadius.^2);
sampleArsMass = sampleArsConc.*(sampleLength.*sampleDensity.*pi.*sampleRadius.^2);
%calculate mass (note that a loop is not necessary)
[sortedMass, sortedID] = sort(sampleGoldMass, 'descend'); %ascend for version B and C
%sort concentrations from high to low, retaining respective sample IDs

for i = 1:size(sortedID,1)
    if ((sampleGoldConc(sortedID(i)) >= goldCutoff)&&(sampleSulfConc(sortedID(i)) <= sulfCutoff)&&(sampleArsConc(sortedID(i)) <= arsCutoff))
        condCutoff(i,1) = 'Y';
    else
        condCutoff(i,1) = 'N';
    end
end %cycle through concentrations and create a column with Y or N based on cutoff grade

fprintf('ID, Gold Mass [g], Sulfur Mass [Kg], Arsenic Mass [Kg], Cutoff conditions? (Y/N)\n'); %print results
for i = 1:size(sortedID, 1)
    fprintf('%d, %0.2f, %0.2f, %0.2f, %c\n',sortedID(i),sortedMass(i),sampleSulfMass(sortedID(i)),sampleArsMass(sortedID(i)),condCutoff(i));
end
[maxMass, maxID] = max(sortedMass); %Extract and print max value
fprintf('Max mass: %0.2f g at ID %d\n', maxMass, sortedID(maxID));
