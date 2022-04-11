#include <math.h>
#include <stdio.h>
#include "header.h"

#define R 6371
#define PI 3.14159265
const float p = PI / 180;

//reference positions
const float refPositions[10][2] = {{34.544909, -102.100843}, {32.345544, -99.123124}, 
								   {33.234235, -100.214124}, {35.195739, -95.348899}, 
								   {31.895839, -97.789573}, {32.895839, -101.789573}, 
								   {34.115839, -100.225732}, {32.335839, -99.992232}, 
								   {33.535339, -94.792232}, {32.234235, -100.222222}};

//================================ Calculate Distance =======================================
float calculateDistance(float latV, float longV, float latRef, float longRef)
{
	float a = 0.5 - cos((latRef-latV)*p)/2 + cos(latV*p)*cos(latRef*p)*(1-cos((longRef-longV)*p))/2;
	float dist = 2*R*asin(sqrt(a));
	return dist;
}

//================================ Calculate Distances ======================================
void calculateDistances(struct leanVehicle vehicles [2000000])
{
	printf("Calculating distances between vehicles and 10 reference points...");
	
	for(int i = 0; i < 2000000; i++){
		for(int j = 0; j < 10; j++){
			vehicles[i].distances[j] = calculateDistance(vehicles[i].latitude, vehicles[i].longitude, refPositions[j][0], refPositions[j][1]);
		}
	}
	
	printf("  done!");
}


