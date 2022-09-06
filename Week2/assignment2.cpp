#include <stdio.h>
#include <math.h>

int main()
{
    //Define the pre-set values.
    float PI = 3.14;
    float INTERNAL_PRICE = 0.0183; // $/mm3
    float BATTERY_PRICE = 0.0095; // $/mm3

    //Define input variables to be used by scanf.
    float pLength, pWidth, pDepth, pRadius;
    
    //Define final variables to be calculated.
    float surfaceArea, volume, materialCost, batteryCost;

    //In the console, enter length, width, depth and radius on a single line, each separated by a comma and space.
	scanf("%f, %f, %f, %f", &pLength, &pWidth, &pDepth, &pRadius);
	
    //Calculation for surface areas of each individual area of the phone.
    float frontFaceArea = (pLength*pWidth) - (2*pRadius*2*pRadius-PI*pow(pRadius,2)); //Front face surface area is the length multiplied by width subtracted by the area of the rounded edges. 
    float topFaceArea = pDepth*(pWidth-2*pRadius); //Top face surface area is the length of the flat section of the top multiplied by the depth.
    float sideFaceArea = pDepth*(pLength-2*pRadius); //Side face surface area is the length of the flat section of the side multiplied by the depth.
    float cornerFacesArea = pDepth*PI*pRadius*2; //All of the corner faces area is the circumference of the corners multiplied by the depth.

    //Calculate final variables.
    surfaceArea = 2*(frontFaceArea+topFaceArea+sideFaceArea)+cornerFacesArea; //Surface area is twice the area of each individual face plus the area of the rounded edges.
    volume = (pLength*pWidth*pDepth) - (pow(pRadius*2,2)*pDepth - PI*pow(pRadius,2)*pDepth); //Volume is the volume of the rectangle subtracted by the volume of the rounded edges.
    materialCost = INTERNAL_PRICE*volume; //Material cost is the volume multiplied by the internal price per per volume. 
    batteryCost = BATTERY_PRICE*volume*0.45; //Battery cost is 45% of the volume multiplied by the battery price per volume.

    //Print out data according to given format.        
    printf("iPhone surface area:\n%.f mm2\n", surfaceArea);
    printf("iPhone volume:\n%.f mm3\n", volume);
    printf("iPhone material cost:\n$%.f\n", materialCost);
    printf("battery cost:\n$%.f\n", batteryCost);
}