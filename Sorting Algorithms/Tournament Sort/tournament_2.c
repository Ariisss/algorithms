#include <stdio.h>
#include <stdlib.h>
#define INF 9999999

void printArray(int arr[], int N);
void swap(int *a, int *b);
void tournaSort(int *arr, int size);

typedef struct{
    int *arr;
    int lastNdx;
}*HEAP;

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 5, 15 , 1, 0 };
    int N = sizeof(arr) / sizeof(arr[0]);

    HEAP heap = (HEAP)malloc(sizeof(HEAP));
    if(heap != NULL){
        heap->arr = (int*)malloc(sizeof(int) * N);
        heap->lastNdx = -1;
    }

    int i;
    for(i = 0; i < N; i++){
        heap->lastNdx++;
        heap->arr[heap->lastNdx] = arr[i];
    }

    printf("Initial Array: \n");
    printArray(heap->arr, heap->lastNdx);

    // tournaSort(arr, N);

    printf("\n\nSorted Array: \n");
    printArray(heap->arr, heap->lastNdx);

    return 0;
}

void tournaSort(int *arr, int size){

    

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i <= N; i++){
        printf("%d ", arr[i]);
    }

}