#include <stdint.h>
#ifndef VEHICLE_H
#define VEHICLE_H

struct vehicle {
	int32_t positionID;
	char registration [15];
	float latitude;
	float longitude;
	uint64_t utcTimestamp;
};

struct leanVehicle {
	int32_t positionID;
	float latitude;
	float longitude;
	float distances [10];
};

struct sortVehicle {
	int32_t positionID;
	float distances [10];
};

#endif

//data
void readData(struct leanVehicle vehicles [2000000]);
void displayTopTen(int32_t topTen [10][10]);

// distance calculation
float calculateDistance(float latV, float longV, float latRef, float longRef);
void calculateDistances(struct leanVehicle vehicles [2000000]);

// sort
void sort2loops(struct leanVehicle vehicles [2000000], int ref);
void selectionSort(struct leanVehicle vehicles [2000000], int ref);
void mergeSort(struct leanVehicle vehicles [2000000], int l, int r, int ref);
void quickSort(struct leanVehicle vehicles [2000000], int low, int high, int ref);