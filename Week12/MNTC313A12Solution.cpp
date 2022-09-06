#include <stdio.h>
#include <math.h>

#define g 9.8
#define PI 3.1415926

int main()
{
	double height, rho;
	
	printf("Enter controlled-descent height (m):\n"); //User input
	scanf("%lf", &height);
	printf("Enter fluid density (kg/m^3):\n");
	scanf("%lf", &rho);
	
	double mass = 15600;
	double P0 = 174850;
	double tGas = 60;
	double dt = 1;
	double speedLimit = 10;
	double r=3.7 /2;
    double A=PI*r*r;
	
	for (int i = 0; i < 3; i++)
	{
		dt = 1/(pow(10, i)); //Define dt values 
		double x = 10000;
		double v = -1500/3.6;
		double t = 0;
		double a = 0;
		double P = -1;
		double tG = 0;
		double indHeight = 0;
		double landingSpeed = 0;
		int j = 1;

		
		while (x >= 0)
		{
			t = (j-1)*dt;
			if (x <= height)
				indHeight=1; //indicator that height was reached
			if ((indHeight == 1)&&(tG<=tGas)){ //Force from pressing gas
				P = P0;
				tG=tG+dt;}
			else
				P = 0;
			
			if (v >= 0)
				a = - g - 0.5*rho*A*v*v/mass + P/mass; //Acceleration from Newton's 2nd law
			else
				a = - g + 0.5*rho*A*v*v/mass + P/mass; //Acceleration from Newton's 2nd law

			x += v*dt;
			v += a*dt;

			j++;
		}
		//For simplicity, values are not stored in arrays on each iteration, but rather only values of interest are kept
		printf("dt = %0.2f s, Total time = %0.0f s, Distance = %0.0f m\n", dt, t, x);
		if (i == 2) //Calculate max speed when dt = 0.01;
		{
			landingSpeed = -v*3.6;
			printf("landing speed: %0.0f km/h\n", landingSpeed);
			if (landingSpeed > speedLimit)
				printf("Non-successful landing\n");
			else
				printf("Successful landing\n");
		}
	}
	
}