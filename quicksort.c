#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partitionhigh(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
int partitionlow(int arr[], int low, int high){  // for first element as pivot
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[j], &arr[i]);
            i++;
        }
    }
    swap(&arr[low], &arr[i-1]);
    return i-1;
}
int getRandom(int low, int high){
    srand(time(0));
    return (rand() % (high - low + 1)) + low;
}
int partitionrandom(int arr[], int low, int high){  // random element as pivot
    int pivotIndex = getRandom(low, high);
    int pivot = arr[pivotIndex];
    swap(&arr[low], &arr[pivotIndex]);
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[j], &arr[i]);
            i++;
        }
    }
    swap(&arr[low], &arr[i-1]);
    return i-1;
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int idx = partitionrandom(array, low, high);
    quickSort(array, low, idx - 1);
    quickSort(array, idx + 1, high);
  }
}
int main(){
    FILE *fptr, *sPtr;
    int index=99;
    int arrNums[100000];
    clock_t t;
    fptr = fopen("Random.txt", "r");
    sPtr = fopen("iTimes.txt", "w");
    for(int i=0; i<=999; i++){
        for(int j=0; j<=index; j++){
            fscanf(fptr, "%d", &arrNums[j]);
        }
        t = clock();
        quickSort(arrNums, 0, index);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        fprintf(sPtr, "%lf\n", time_taken);
        printf("%lf\n", time_taken);
        index = index + 100;
        fseek(fptr, 0, SEEK_SET);
    }
    fclose(sPtr);
    fclose(fptr);

    return 0;
}
