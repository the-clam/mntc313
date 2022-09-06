clear all
clc

target = 36000;

prompt = 'Input customer data for all centers: ';
centerData.numCustomers = input(prompt); %define structure fields
prompt = 'Input item average price data for all centers: ';
centerData.avItemPrice = input(prompt);
prompt = 'Input item average weight data for all centers: ';
centerData.avKgTransported = input(prompt);
centerData.costPerTransporKG = 4.70;
N = numel(centerData.numCustomers);

flightSet = multiCenters(centerData.numCustomers,centerData.avItemPrice,centerData.avKgTransported,centerData.costPerTransporKG);
%Create class
[customersServed,weightTransported,revenue] = flightSet.totals; %call class
avgRev = revenue/N;

fprintf('Total customers: %d\n', customersServed); %print results
fprintf('Total weight: %0.0f kg\n', weightTransported);
fprintf('Total revenue: $%0.0f\n', revenue);
fprintf('Average revenue: $%0.0f\n', avgRev);
	
if avgRev >= target
	fprintf('Company is profitable\n');
else
	fprintf('Company is not profitable\n');
end