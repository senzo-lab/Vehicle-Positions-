#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "header.h"


//================================= Skip registration =======================================
void skipRegistration(FILE * positionsFile)
{
	int ch = 1;

	while(ch != 0){
		fread(&ch, sizeof(char), 1, positionsFile);
		//printf("%c", ch);
	}
}

//================================= Read data from positions.dat ============================
void readData(struct leanVehicle vehicles [2000000])
{
	FILE * positionsFile = fopen("positions.dat", "rb");
	
	// exit if file not found
	if(positionsFile == NULL){
		printf("There was a problem reading the file");
		exit(1);
	}
	
	printf("Reading data...");  //progress
	for(int i = 0; i < 2000000; i++){
		struct leanVehicle tempVehicle;
		//read positionID
		fread(&tempVehicle.positionID, sizeof(int32_t), 1, positionsFile);
		//skip registration
		skipRegistration(positionsFile);
		// get latitude
		fread(&tempVehicle.latitude, 4, 1, positionsFile);
		// get longitude
		fread(&tempVehicle.longitude, 4, 1, positionsFile);
		// skip utc timestamp
		fseek(positionsFile, sizeof(uint64_t), SEEK_CUR);
		
		vehicles[i] = tempVehicle;
	}
	printf("  done!");
	
	fclose(positionsFile);
}

//==================================== Display top ten vehicles ================================
void displayTopTen(int32_t topTen [10][10])
{
	printf("\n===============================================================================================================");
	printf("\n            POINT 1   POINT 2   POINT 3   POINT 4   POINT 5   POINT 6   POINT 7   POINT 8   POINT 9   POINT 10");
	printf("\n===============================================================================================================");
	
	for(int i = 0; i < 10; i++){
		printf("\n     %2d     %7d   %7d   %7d   %7d   %7d   %7d   %7d   %7d   %7d   %7d", i+1, topTen[0][i], topTen[1][i], topTen[2][i], topTen[3][i], topTen[4][i], topTen[5][i], topTen[6][i], topTen[7][i], topTen[8][i], topTen[9][i]);
	}
	
	printf("\n_______________________________________________________________________________________________________________");
}