#include <stdio.h>
#include <string>
//Needed for string manipulation
using std::string;

int main()
{
	float unitWeight, firstDepth, depthIncrement, firstK, kIncrement;
	int Nd;
	int Nk;
	//Recommend floats for all variables except N, but test cases used mostly whole numbers so int would be acceptable
	
	printf("Input rock unit weight (kN/m3):\n"); //User input statements
	scanf("%f", &unitWeight);
	printf("Input number of depth values:\n");
	scanf("%d", &Nd);
	printf("Input first depth value (m):\n");
	scanf("%f", &firstDepth);
	printf("Input depth increment (m):\n");
	scanf("%f", &depthIncrement);
	printf("Input number of k values:\n");
	scanf("%d", &Nk);
	printf("Input first k value (m):\n");
	scanf("%f", &firstK);
	printf("Input k increment (m):\n");
	scanf("%f", &kIncrement);
	
	float depthVals[Nd], kVals[Nk], stressV[Nd], stressH[Nd][Nk];
	
	printf("Vertical stress values (kPa):\n"); //"Horizontal stress values (kPa)" for Version B, "Depth values (m)" for Version C
	for (int i = 0; i < Nd; i++)
	{
		depthVals[i] = firstDepth + depthIncrement*i;
		stressV[i] = unitWeight*depthVals[i];
		printf("%0.0f\n", stressV[i]); 
		for (int j = 0; j < Nk; j++)
		{
		kVals[j] = firstK + kIncrement*j;
		stressH[i][j] = stressV[i]*kVals[j];
		}
	}
	
	string filename = "outputFileA.txt"; //Set file name//...B.txt for version B, ..C.txt for version C
	FILE* fileOutput = fopen(filename.c_str(), "w"); //Open file
	
	for (int i = 0; i < Nd; i++)
	{
		for (int j = 0; j < Nk; j++)
		{
		if ((j == (Nk - 1))&&(i < (Nd - 1)))
			fprintf(fileOutput, "%0.0f\n", stressH[i][j]);  //Write values to file separated by a comma. No newline for last data row
		else if ((j == (Nk - 1))&&(i == (Nd - 1)))
			fprintf(fileOutput, "%0.0f", stressH[i][j]); 
		else if (j == 0)
			fprintf(fileOutput, "%0.0f,%0.0f,", depthVals[i], stressH[i][j]);
		else
			fprintf(fileOutput, "%0.0f,", stressH[i][j]); 
		}
	}
	
	fclose(fileOutput); //Close file
}