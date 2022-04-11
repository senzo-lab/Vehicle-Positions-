#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//=============================== Sort by distance: 2 inner for loops =======================
void sort2loops(struct leanVehicle vehicles [2000000], int ref)
{
	int i, j;
	struct leanVehicle t;
	int numVehicles = 2000000;
	
	for (i = 0; i < numVehicles - 1; i++){
		for (j = 0; j < numVehicles - i - 1; j++){
			if (vehicles[j].distances[ref] > vehicles[j + 1].distances[ref]){
				t = vehicles[j];
				vehicles[j] = vehicles[j + 1];
				vehicles[j + 1] = t;
			}
		}
	}
}

//=============================== Selection Sort ======================================
void selectionSort(struct leanVehicle vehicles [2000000], int ref)
{	
	int numVehicles = 2000000;
	
	for(int i = 0; i < numVehicles - 1; i++){
		int min_pos = i;
		for(int j = i + 1; j < numVehicles; j++){
			if(vehicles[j].distances[ref] < vehicles[min_pos].distances[ref]){
				min_pos = j;
			}
		}
		
		if(min_pos != i){
			struct leanVehicle temp = vehicles[i];
			vehicles[i] = vehicles[min_pos];
			vehicles[min_pos] = temp;
		}
	}
}

//================================== Merge Sort =============================================
// Merge two subarrays L and M into arr
void merge(struct leanVehicle vehicles [2000000], int p, int q, int r, int ref) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  //struct leanVehicle L[n1], M[n2];
  struct leanVehicle *L = calloc( n1, sizeof( struct leanVehicle ) );
  struct leanVehicle *M = calloc( n2, sizeof( struct leanVehicle ) );

  for (int i = 0; i < n1; i++)
    L[i] = vehicles[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = vehicles[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i].distances[ref] <= M[j].distances[ref]) {
      vehicles[k] = L[i];
      i++;
    } else {
      vehicles[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    vehicles[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    vehicles[k] = M[j];
    j++;
    k++;
  }
  
  free(L);
  free(M);
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(struct leanVehicle vehicles [2000000], int l, int r, int ref) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(vehicles, l, m, ref);
    mergeSort(vehicles, m + 1, r, ref);

    // Merge the sorted subarrays
    merge(vehicles, l, m, r, ref);
  }
}

//======================================= Quicksort ====================================
// function to find the partition position
int partition(struct leanVehicle vehicles [2000000], int low, int high, int ref) {
  
  struct leanVehicle temp;
  
  // select the rightmost element as pivot
  struct leanVehicle pivot = vehicles[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (vehicles[j].distances[ref] <= pivot.distances[ref]) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      //swap(&array[i], &array[j]);
	  temp = vehicles[i];
	  vehicles[i] = vehicles[j];
	  vehicles[j] = temp;
    }
  }

  // swap the pivot element with the greater element at i
  //swap(&array[i + 1], &array[high]);
  temp = vehicles[i + 1];
  vehicles[i + 1] = vehicles[high];
  vehicles[high] = temp;
  
  // return the partition point
  return (i + 1);
}

void quickSort(struct leanVehicle vehicles [2000000], int low, int high, int ref) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(vehicles, low, high, ref);
    
    // recursive call on the left of pivot
    quickSort(vehicles, low, pi - 1, ref);
    
    // recursive call on the right of pivot
    quickSort(vehicles, pi + 1, high, ref);
  }
}