#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int *elems;
    int count;
}ARRAY;

void countSort(ARRAY *arr);
void printArray(int arr[], int N);

int main(){

    ARRAY arr;
    arr.elems = (int*)malloc(sizeof(int) * MAX);
    arr.count = 0;

    int values[] = {8, 2, 7, 5, 0, 9, 1, 2, 5, 3};

    int i;
    for(i = 0; i < MAX; i++){
        arr.elems[i] = values[i];
        arr.count++;
    }
    // countSort(&arr);
    
    printArray(arr.elems, arr.count);

}

// 1) find max element
// 2) create count array (0 - max)
// 3) add element count/frequency
// 4) turn countArray to prefix sum
// 5) fill the output array


void countSort(ARRAY *arr){

    

}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }

}