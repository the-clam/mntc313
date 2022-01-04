#include <stdio.h>
#include <math.h> //Needed if using power function

#define PHONEUNIT 0.0183 
#define BATTERYUNIT 0.0095
#define PI 3.14

int main()
{
	float phoneSurf, phoneVol, phoneCost, batteryCost, phoneSurf_face, phoneSurf_facePerimeter;
	float phoneSurf_border,batteryVol;//Variables for storing answers
	float pLength, pWidth, pDepth, pRadius; 
	
	scanf("%f, %f, %f, %f", &pLength, &pWidth, &pDepth, &pRadius);
	
	phoneSurf_face = (pLength-2*pRadius)*(pWidth-2*pRadius)+2*(pLength-2*pRadius)*(pRadius)+2*(pWidth-2*pRadius)*(pRadius)+PI*pRadius*pRadius; 
	phoneSurf_facePerimeter = 2*(pLength-2*pRadius) + 2*(pWidth-2*pRadius)+2*PI*pRadius;
	phoneSurf_border = pDepth*phoneSurf_facePerimeter;
	phoneSurf = 2*phoneSurf_face + phoneSurf_border;

	phoneVol = phoneSurf_face*pDepth;
	phoneCost = PHONEUNIT * phoneVol;
	batteryVol = phoneVol*0.45;
	batteryCost = BATTERYUNIT * batteryVol;
	
	printf("iPhone surface area:\n%0.0f mm2\n", phoneSurf);
	printf("iPhone volume:\n%0.0f mm3\n", phoneVol);
	printf("iPhone material cost:\n$%0.0f\n", phoneCost); 
	printf("battery cost:\n$%0.0f\n", batteryCost);
	
}

/* Output
160.84,78.09,7.4,15.16
iPhone surface area:
28068 mm2
iPhone volume:
91481 mm3
iPhone material cost:
$1674
battery cost:
$391
*/