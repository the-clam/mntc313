#include <stdio.h>
#include <math.h>

int main()
{
	//Define preset values.
	float GRAVITY = 9.81;
	float PI = 3.14;

	//Define input variables to be used with scanf.
	float time,initVel,initAng,initH;

	//Define final variables to be calculated.
	float position,verticalVel,initRadians;

	//In the console, enter time, initial velocity, initial angle and initial height values on a single line separated by a comma and space.
	scanf("%f, %f, %f, %f", &time, &initVel, &initAng, &initH);

	//Converts the initial angle from degrees to radians.
	initRadians = initAng*PI/180;

	//Calculate the position and velocity using given formulas.	
	position = -0.5*GRAVITY*pow(time,2) + initVel*sin(initRadians)*time + initH;
	verticalVel = -GRAVITY*time + initVel*sin(initRadians);
	
	if(time>=0)
	{
		//Display the position and velocity if there is time elapsed.
		printf("Projectile released\n");
		printf("Position: %.2f meters\n", position);
		printf("Velocity value: %.2f meters/second\n", verticalVel);

		//Check sign of velocity to determine direction of travel.
		if(verticalVel >= 0)
		{
			printf("Projectile ascending\n");
		}
		else
		{
			printf("Projectile descending\n");
		}

		//Compare position with initial height.
		if(position >= initH)
		{
			printf("Projectile above initial position\n");
		}
		else
		{
			printf("Projectile below initial position\n");
		}
	}
	else
	{
		printf("Projectile not released\n");
	}
}