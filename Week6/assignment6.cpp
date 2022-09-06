#include <stdio.h>

//Define maximum tension and compression values.
#define maxTension 5
#define maxCompression -30

//Initialize function.
float calculateTension(float elasticMod, float strain);

int main()
{
	//Declare variables to use in main program.
	float elasticMod, strain;
	
	//In the console, enter elastic modulus (MPa) and strain values on a single line separated by a comma and space.
	scanf("%f, %f", &elasticMod, &strain);
	
	//Use function to calculate tension.
	float tension = calculateTension(elasticMod, strain);

	//Output appropriate message based on calculated tension value.
	if(tension > 0)
	{
		printf("Bridge deck in tension\n");
		if(tension > maxTension)
		{
			printf("Danger: tensile strength exceeded\n");
		} 
		else
		{
			printf("Bridge deck safe\n");
		}
	}
	else if (tension < 0)
	{
		printf("Bridge deck in compression\n");
		if(tension < maxCompression)
		{
			printf("Danger: compressive strength exceeded\n");
		} 
		else
		{
			printf("Bridge deck safe\n");
		}
	}
	else
	{
		printf("No stress in bridge\n");
	}
}

//Function to calculate & print tension, given an elastic modulus and strain.
float calculateTension(float elasticMod, float strain)
{
	float tension = elasticMod * strain;
	printf("Stress value: %2.2f MPa\n", tension);
	return tension;
}