#include <stdio.h>
#include <stdlib.h>
#define INF 9999999

void printArray(int arr[], int N);
void swap(int *a, int *b);
void tournaSort(int *arr, int size);

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 5, 15 , 1, 0 };
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Initial Array: \n");
    printArray(arr, N);

    // tournaSort(arr, N);

    printf("\n\nSorted Array: \n");
    printArray(arr, N);

    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }

}