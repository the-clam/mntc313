#include <stdio.h>
#include <math.h>

#define N 12 //Number of coordinate values.

int main()
{
	float coordinates[N][2]; //Initialize array for points.
	float coordinatesDistance[N][N]; //Initialize array to store distances.
	
	//In the console, enter the 12 coordinate values on a single line separated by comma and by spaces (ie. 1.1,5.6 5.5,8.2 etc.)
	for (int i = 0; i < N; i++)
	{
		scanf("%f, %f", &coordinates[i][0],&coordinates[i][1]);
	}

	//Print out formatted coordinates.
	for (int i = 0; i < N; i++)
	{  
		printf("(%.1f,%.1f)", coordinates[i][0], coordinates[i][1]);
		if(i != N-1)
		{
			printf(",");
		}
		if(i == 5 || i == N-1)
		{
			printf("\n");
		}
	}
	
	//Declare variables to be used in average calculation.
	float avgX, avgY;
	float avgXTotal = 0;
	float avgYTotal = 0;
	
	//Calculate average of X and Y coordinates.
	for(int i = 0; i < N; i++)
	{
		avgXTotal += coordinates[i][0];
		avgYTotal += coordinates[i][1];
	}
	avgX = avgXTotal/N;
	avgY = avgYTotal/N;
		
	//Calculate distances between points and populate distance array.
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			float xDistance = (coordinates[j][0]-coordinates[i][0]);
			float yDistance = (coordinates[j][1]-coordinates[i][1]);
			//Pythagorean theorem used.
			coordinatesDistance[i][j] = sqrtf((powf(xDistance,2)) + (powf(yDistance,2)));
		}
	}

	//Print average coordinates.
	printf("\nAverage center: (%.1f,%.1f)\n\n", avgX, avgY);

	//Print values in distance array.
	for(int i = 0; i < N; i++)
	{
		printf("Distance from point %d to\n", i+1);
		for(int j = 0; j < N; j++)
		{
			printf("%d.- %.1f", j+1, coordinatesDistance[i][j]);
			if(j != N-1)
			{
				printf(", ");
			}
			else
			{
				printf("\n");
			}
		}
	}
	printf("\n");

	//Print average distances.
	for(int i = 0; i < N; i++)
	{
		float avgDistTotal = 0;
		for(int j = 0; j < N; j++)
		{
			avgDistTotal += coordinatesDistance[i][j];
		}
		float avgDist = avgDistTotal/11;
		printf("Average distance from point %d: %.1f km\n", i+1, avgDist);
	}
}