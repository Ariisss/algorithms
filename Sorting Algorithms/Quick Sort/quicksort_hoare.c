#include <stdio.h>
#include <stdlib.h>
#define MAX 6
// #define MAX 10

typedef struct
{
    int *elems;
    int count;
} ARRAY;

void quicksort(ARRAY *arr, int low, int high);
int partition(ARRAY *arr, int low, int high);
void swap(int *x, int *y);
void printArray(int arr[], int N);

int main(){
    ARRAY arr;
    arr.elems = (int *)malloc(sizeof(int) * MAX);
    arr.count = 0;

    // int values[] = {5, 1, 3, -3, 0, 7};
    int values[] = {6, 5, 4, 3, 2, 1};
    // int values[] = {8, 2, 7, -5, 0, 9, 1, 2, -1, 3};


    int i;
    for (i = 0; i < MAX; i++)
    {
        arr.elems[i] = values[i];
        arr.count++;
    }

    quicksort(&arr, 0, MAX-1);
    printArray(arr.elems, MAX);
}

void quicksort(ARRAY *arr, int low, int high){

    if(low < high){
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }

}

int partition(ARRAY *arr, int low, int high){

    int pivot = arr->elems[high];
    int i = low, j = high;

    while(i < j){
        
        while(i < j && arr->elems[i] < pivot) i++;
        while(j > i && arr->elems[j] >= pivot) j--;

        if(i < j){
            swap(&arr->elems[j], &arr->elems[i]); 
        }
    }

    swap(&arr->elems[i], &arr->elems[high]);
    return i;
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printArray(int arr[], int N)
{	
	int i;
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}