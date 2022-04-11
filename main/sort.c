#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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
