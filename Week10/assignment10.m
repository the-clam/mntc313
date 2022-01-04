%Clear all previous variables/console.
clear
clc

%Input data from text file into a 2D array.
input = dlmread('goldDataA.txt');

%Calculate the masses of all gold samples and put in an array.
for i = 1:1:height(input)
    calcMass(i) = findMass(input(i,2),input(i,3),input(i,4),input(i,5));
end
clear i

%Sort the gold masses from largest to smallest, with another array being ordered in parallel with each sample's associated ID.
[goldMassSorted,orderedID] = sort(calcMass,'descend');

%Use the sorted ID numbers taken from previous sort to calculate output data in the required order.
for i = 1:1:height(input)
    output(i,1) = orderedID(i);
    output(i,2) = calcMass(input(output(i,1)));
    output(i,3) = findMass(input(output(i,1),2),input(output(i,1),3),input(output(i,1),4),input(output(i,1),6));
    output(i,4) = findMass(input(output(i,1),2),input(output(i,1),3),input(output(i,1),4),input(output(i,1),7));
    %Check cutoff data and add appropriate letter to output array.
    if(input(output(i,1),5) < 1 || input(output(i,1),6) > 5 || input(output(i,1),7) > 1)
        output(i,5)='N';
    else
        output(i,5)='Y';
    end
end
clear i

%Printing out the titles for each section of data.
fprintf('ID, Gold Mass [g], Sulfur Mass [Kg], Arsenic Mass [Kg], Cutoff conditions? (Y/N)\n');

%Output all required data to console.
for i=1:1:height(output)
    fprintf("%d, %0.2f, %0.2f, %0.2f, %c\n", output(i,1), output(i,2), output(i,3), output(i,4), output(i,5));
end
clear i

%Print out the information for the sample with the most gold.
fprintf("Max mass: %0.2f g at ID %d\n", output(1,2),output(1,1));

%Function to calculate the mass of the mineral in the sample.
function [mass] = findMass(length, radius, density, concentration)
    mass = pi * radius^2 * length * density * concentration;
end