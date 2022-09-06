#include <stdio.h>
#include <math.h> //Needed for sin() in C++

#define PI 3.14
#define g 9.81

int main()
{
	float time, initVel,initAng,initH;
	float currentH,currentVel;
	//Define variables
	scanf("%f, %f, %f, %f", &time, &initVel, &initAng, &initH);
	//Enter time, initial velocity, initial angle and initial heigth
	currentH = -(1.0/2.0)*g*time*time + initVel*sin(PI*initAng/180)*time + initH;
	currentVel = -g*time + initVel*sin(PI*initAng/180);

	
	if (time > 0) //Positive time case
	{
		printf("Projectile released\n");
		printf("Position: %0.2f meters\n", currentH);
		printf("Velocity value: %0.2f meters/second\n", currentVel);
		

		if (currentVel >= 0) //Ascending case
		{	
			printf("Projectile ascending\n");
			if (currentH >= initH) //vertical position greater or equal than the initial position
				printf("Projectile above initial position\n");
			//else //no required
			//	printf("Projectile below initial position\n"); //I will leave this here in case of negative gravity
		}
		
		else //Descending case
		{
			printf("Projectile descending\n");			
			if (currentH >= initH) //vertical position greater or equal than the initial position
				printf("Projectile above initial position\n");
			else
				printf("Projectile below initial position\n");
		}
	}
	else //Case if time is negative
		printf("Projectile not released\n");
}