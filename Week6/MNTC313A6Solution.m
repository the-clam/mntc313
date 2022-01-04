clear all
clc

prompt = 'Enter elastic modulus and strain: ';
data = input(prompt, 's');
data = sscanf(data, '%f');
elasticMod = data(1, :);
strain = data(2, :);

stressCalc(elasticMod, strain);