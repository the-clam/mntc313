//Include neccessary libraries and namespaces.
#include <stdio.h>
#include <string>

using namespace std;

#define TRANSPORT_FLAT_RATE 4.70 //Price per kilogram for transportation.
#define MIN_AVG_REVENUE 36000 //Minimum average revenue for company to remain profitable.

//Structure with neccessary information for a single fulfillment center.
struct centerPayload
{
    int numCustomers; //Number of customers per facility.
    float avgItemPrice, avgItemWeight; //Average item price in $ and item weight kg.
};

//Class with neccessary functions to calculate information for the facilities.
class centerEconomics
{
    public:
        //Required variables for the centerEconomics class.
        float transportCost, minNeededRevenue;
        
        //Constructor for centerEconomics; initializes declared variables.
        centerEconomics(float theTransportCost, float theMinNeededRevenue)
        {
            transportCost = theTransportCost;
            minNeededRevenue = theMinNeededRevenue;
        }

        //Function to calculate total customers across all distribution centers.
        int calcTotalCustomers(centerPayload theCenters[], int numCenters)
        {
            int totalCustomers = 0;
            for(int i = 0; i < numCenters; i++)
                totalCustomers += theCenters[i].numCustomers;
            return totalCustomers;
        }

        //Function to calculate total weight of cargo across all distribution centers.
        float calcTotalWeight(centerPayload theCenters[], int numCenters)
        {
            float totalWeight = 0;
            for(int i = 0; i < numCenters; i++)
                totalWeight += theCenters[i].avgItemWeight * theCenters[i].numCustomers;
            return totalWeight;
        }

        //Function to calculate total or average revenue across all distribution centers.
        float calcRevenue(centerPayload theCenters[], int numCenters, bool findAvg)
        {
            float totalRevenue = 0;
            for(int i = 0; i < numCenters; i++)
                totalRevenue += theCenters[i].avgItemPrice * theCenters[i].numCustomers;

            //Subtract the cost of shopping across all facilities by using another class function.
            totalRevenue -= this->calcTotalWeight(theCenters, numCenters) * TRANSPORT_FLAT_RATE;
            
            //Enacts the averaging portion of the code only if it is requested by user inputting "true".
            if(findAvg)
                totalRevenue = totalRevenue/numCenters;

            return totalRevenue;
        }

        //Function to print message about the profitability of the centers.
        void profitability(centerPayload theCenters[], int numCenters)
        {
            //Evaluates the actual average revenue of the facility against the minimum profitable revenue to print appropriate message.
            if(this->calcRevenue(theCenters,numCenters, true) >= minNeededRevenue)
                printf("Company is profitable\n");
            else
                printf("Company is not profitable\n");
        }      
};

int main()
{
    //Required input variable.
    int numCenters;
    
    //User input for number of centers.
    printf("Input number of centers:\n");
    scanf("%d", &numCenters);

    //Create the appropriate number of class instances for each fulfillment center payload/facility economics class.
    centerPayload centers[numCenters];
    centerEconomics economics(TRANSPORT_FLAT_RATE, MIN_AVG_REVENUE);

    //Get data required for all of the center payloads fields.
    printf("Input customer data for all centers:\n");
    for(int i = 0; i < numCenters; i++)
    {
        scanf("%d", &centers[i].numCustomers);
    }
    printf("Input item average price data for all centers:\n");
    for(int i = 0; i < numCenters; i++)
    {
        scanf("%f", &centers[i].avgItemPrice);
    }
    printf("Input item average weight data for all centers:\n");
    for(int i = 0; i < numCenters; i++)
    {
        scanf("%f", &centers[i].avgItemWeight);
    }

    //Use centreEconomics class functions to calculate the required data and print it to the console.
    printf("Total customers: %d\n", economics.calcTotalCustomers(centers,numCenters));
    printf("Total weight: %.0f kg\n", economics.calcTotalWeight(centers,numCenters));
    printf("Total revenue: $%.0f\n", economics.calcRevenue(centers,numCenters, false));
    printf("Average revenue: $%.0f\n", economics.calcRevenue(centers,numCenters, true));
    economics.profitability(centers,numCenters);
}