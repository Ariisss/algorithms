#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct
{
    int *elems;
    int count;
} ARRAY;

void quicksort(ARRAY *arr, int low, int high);
int partition(ARRAY *arr, int low, int high);
void swap(int *x, int *y);
void printArray(int arr[], int N);

int main()
{

    ARRAY arr;
    arr.elems = (int *)malloc(sizeof(int) * MAX);
    arr.count = 0;

    int values[] = {8, 2, 7, -5, 0, 9, 1, 2, -1, 3};

    int i;
    for (i = 0; i < MAX; i++)
    {
        arr.elems[i] = values[i];
        arr.count++;
    }

    quicksort(&arr, 0, MAX-1);
    printArray(arr.elems, MAX);

}

void quicksort(ARRAY *arr, int low, int high)
{

    if(low < high){
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }

}

// 1) set pivot as last element
// 2) if arr[i] is lesser than pivot and i != j, swap it with arr[j].
// 3) if arr[i] is greater than pivot, increment only i, no swaps
// 4) repeat 2 until end of loop
// 5) swap arr[high] (pivot) with arr[j] then return j

int partition(ARRAY *arr, int low, int high)
{
    int pivot = arr->elems[high];
    int i, j = low;

    for (i = low; i < high; i++)
    {
        if (arr->elems[i] <= pivot)
        {
            swap(&arr->elems[i], &arr->elems[j]);
            j++;
        }
    }

    swap(&arr->elems[j], &arr->elems[high]);
    return j;
}

void swap(int *x, int *y)
{
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