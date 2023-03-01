#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    count++;
}

int getRandom(int low, int high){
    srand(time(0));
    return (rand() % (high - low + 1)) + low;
}

int partition1(int arr[], int low, int high){  // for first element as pivot
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

int partition2(int arr[], int low, int high){  // random element as pivot
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

int partition3(int arr[], int low, int high){   // last element as pivot 
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int pivot = partition3(arr, low, high);    // run par1, par2, par
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(){
    FILE *fptr, *sPtr;
    int index=99;
    int arrNums[100000];
    clock_t t;
    fptr = fopen("Random.txt", "r");
    sPtr = fopen("swaps3.txt", "w");   // get 3 txt files, i.e swaps 1, 2, 3
    for(int i=0; i<=999; i++){
        for(int j=0; j<=index; j++){
            fscanf(fptr, "%d", &arrNums[j]);
        }
        quickSort(arrNums, 0, index);
        fprintf(sPtr, "%d\n", count);
        printf("%d\n", count);
        index = index + 100;
        fseek(fptr, 0, SEEK_SET);
        count = 0;
    }
    fclose(sPtr);
    fclose(fptr);
    return 0;
}
