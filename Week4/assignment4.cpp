#include <stdio.h>
#include <math.h>

int main()
{
	//Define static values.
	float GRAVITY = 9.81;
	float PI = 3.14;

	//Define input variables.
	float initialHeight, tankRad, pipeRad;
	int finalT;

	//Define variables to be used in caluclations/results.
	float curVel, curHeight, curVol, avgVelTotal, avgVel, halfHourHeight;

	//In the console, enter initial height, tank radius, pipe radius and final time separated by a comma and a space.
	scanf("%f, %f, %f, %d", &initialHeight, &tankRad, &pipeRad, &finalT);
	
	//Set the initial values of height and volume.
	curHeight = initialHeight;
	curVol = PI*pow(tankRad, 2)*curHeight;
	
	for(int t = 0; t <= finalT; t++)
	{	
		curVel = 0.5*sqrtf(2*GRAVITY*curHeight); //Calculate current velocity.
		curVol -= curVel * PI*pow(pipeRad,2)*1; //Subtract volume from total volume based off current water velocity.
		curHeight = curVol/(PI*pow(tankRad,2)); //Set current height based on new volume.
		avgVelTotal += curVel; //Add current velocity to later calculate average velocity.

		//Logs the height of the water after 30 mins has passed.
		if(t == 1800)
		{
			halfHourHeight = curHeight;
		}
	}

	//Calculate average water velocity.
	avgVel = avgVelTotal/finalT;

	//Print the given data.
	printf("Average velocity value: %.2f m/s\n", avgVel);
	printf("Height value after 30 min: %.2f m\n", halfHourHeight);
	printf("Height value after %d seconds: %.2f m\n", finalT, curHeight);

	//Checks to see if the tank is half empty and prints appropriate final message.
	if(curHeight <= 0.5*initialHeight)
	{
		printf("Tank half drained\n");
	} 
	else
	{
		printf("Tank still not half drained\n");
	}
}