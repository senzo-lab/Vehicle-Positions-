#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main()
{
	struct leanVehicle *vehicles = calloc( 2000000, sizeof( struct leanVehicle ) );   //positions data
	clock_t start_t, end_t;		 												  	  //timing
	double total_t = 0;
	int topTen [10][10];															  //closest vehicles to reference points
	
	
	// Read positions.dat
	//=========================================================================================
	start_t = clock();
	readData(vehicles);  									//read data
	end_t = clock();
	double diff_t = (end_t - start_t) / CLOCKS_PER_SEC;
	total_t += diff_t;
	printf("  [%.1f seconds]\n", diff_t);
	
	// calculate distance between vehicles and the 10 reference points
	//=========================================================================================
	start_t = clock();
	calculateDistances(vehicles);							//calculate distances
	end_t = clock();
	diff_t = (end_t - start_t) / CLOCKS_PER_SEC;
	total_t += diff_t;
	printf("  [%.1f seconds]\n", diff_t);
	
	// Sort based on smallest distances: Merge Sort Alogorithm
	//=========================================================================================
	printf("\nFinding the 10 closest vehicles (Merge Sort algo)\n");
	start_t = clock();
	for(int i = 0; i < 10; i++){
		mergeSort(vehicles, 0, 2000000 - 1, i);				// Sort
		printf("Point: %d  ", i + 1);
		for(int j = 0; j < 10; j++){
			topTen[i][j] = vehicles[j].positionID;
		}
	}
	end_t = clock();
	diff_t = (end_t - start_t) / CLOCKS_PER_SEC;
	total_t += diff_t;
	
	displayTopTen(topTen);
	printf("\nSort time:  %dm%ds\n", (int)diff_t/60, (int)diff_t%60);
	printf("\nTotal time (read data, calculate distances, sort):  %dm%ds\n", (int)total_t / 60, (int)total_t % 60);
	
	printf("Press any key to exit");
	scanf("%d", &algo);
	
	return 0;
}