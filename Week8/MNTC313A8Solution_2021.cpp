#include <stdio.h>
#define TARGET 36000

struct centerData //structure definition
{
	int numCustomers; //fields for number of customers, ave. item price, and ave. weight of transportation
	float avItemPrice;
	float avKgTransported;
};

class multiCenters //class definition
{
public:
	float costPerTransporKG;
	
	int totalCustomers(centerData centers[], int numCenters) //Function takes array of structures and number of centers
	{
		int totCust = 0;
		for (int i = 0; i < numCenters; i++)
		{
			totCust += centers[i].numCustomers; //Total customers calculation
		}
		return totCust;
	}
	
	float totalWeight(centerData centers[], int numCenters)
	{
		float totWei = 0;
		for (int i = 0; i < numCenters; i++)
		{
			totWei += centers[i].avKgTransported*centers[i].numCustomers; //Total transported weight
		}
		return totWei;
	}
	
	float totalRevenue(centerData centers[], int numCenters)
	{
		float totRev = 0;
		for (int i = 0; i < numCenters; i++)
		{
			totRev += centers[i].numCustomers*centers[i].avItemPrice - centers[i].avKgTransported*centers[i].numCustomers*costPerTransporKG;
			//Total revenue calculation
		}
		return totRev;
	}
};

int main()
{
	int N, customersServed;
	float weightTransported, revenue, avgRev;
	
	printf("Input number of centers:\n");
	scanf("%d", &N);
	
	centerData centerSet[N]; //Declare array of structures
	
	printf("Input customer data for all centers:\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &centerSet[i].numCustomers); //Read values into structure
	}
	printf("Input item average price data for all centers:\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%f,", &centerSet[i].avItemPrice);
	}
	printf("Input item average weight data for all centers:\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%f,", &centerSet[i].avKgTransported);
	}
	
	multiCenters inputSet; //Declare class
	inputSet.costPerTransporKG = 4.70;
	customersServed = inputSet.totalCustomers(centerSet, N); //Pass values to the class for calculations
	weightTransported = inputSet.totalWeight(centerSet, N);
	revenue = inputSet.totalRevenue(centerSet, N);
	avgRev = revenue/N;
	
	printf("Total customers: %d\n", customersServed); //Print results
	printf("Total weight: %0.0f kg\n", weightTransported);
	printf("Total revenue: $%0.0f\n", revenue);
	printf("Average revenue: $%0.0f\n", avgRev);
	
	if (avgRev >= TARGET)
		printf("Company is profitable\n");
	else
		printf("Company is not profitable\n");
}