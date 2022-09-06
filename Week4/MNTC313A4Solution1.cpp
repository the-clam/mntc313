#include <stdio.h>
#include <math.h> //Needed for power function

#define PI 3.14
#define g 9.81

int main()
{
	float initialVol, pipeSurf, tankSurf, currentVol, currentHeight, Q, deltaVol, heightHalfH, Vel, VelSum, avgVel;
	float initialHeight, tankRad, pipeRad;
	int finalT;
	
	scanf("%f, %f, %f, %d", &initialHeight, &tankRad, &pipeRad, &finalT);
	//In the console, enter initial height, tank radius, pipe radius and final time separated by a comma and a space
	pipeSurf = pipeRad*pipeRad*PI;
	tankSurf = tankRad*tankRad*PI;
	initialVol = initialHeight*tankSurf;
	currentVol = initialVol;
	currentHeight = initialHeight;
	
	VelSum=0;
	
	for (int t = 0; t <= finalT; t++) //Run loop including time 0, and including the final time
	{
		Vel = 0.5*pow(2*g*currentHeight,0.5);
		VelSum+=Vel;
		Q = Vel*pipeSurf;
		deltaVol=Q*1;
		currentVol=currentVol-deltaVol;
		currentHeight=currentVol/tankSurf;
		
		if (t == 1800) //Store values of interest
			heightHalfH = currentHeight;
	}
	
	avgVel = VelSum / finalT; //Calculate average value
	
	printf("Average velocity value: %0.2f m/s\n", avgVel); //Print results
	printf("Height value after 30 min: %0.2f m\n", heightHalfH);
	printf("Height value after %d seconds: %0.2f m\n", finalT, currentHeight);
	
	if (currentHeight <= 0.5*initialHeight) //Print status
		printf("Tank half drained\n");
	else
		printf("Tank still not half drained\n");
}