#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int N);
void swap(int *a, int *b);
void tournaSort(int *arr, int size);

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 5, 15 , 1, 0 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // tournaSort(arr, N);

    return 0;
}

void tournaSort(int *arr, int size){

    int heapSize = (size * 2 - 1);
    int* heap = (int*)malloc(heapSize * sizeof(int));

    int i, j, x = heapSize;
    int winFlag = 0;

    for(i = size - 1; i >= 0; i--){
        heap[x - 1] = arr[i];
        x--;
    }

    for(i = 0; i < size; i++){

        for(j = (heapSize/2) - 1; j >= 0; j--){
            
            int LC = (j*2) + 1;
            int RC = (j*2) + 2;
            
            int left = LC < heapSize - size ? heap[LC] : LC;
            int right = RC < heapSize - size ? heap[RC] : RC;

            heap[j] = heap[left] < heap[right] ? left : right;

            j = (i > 0 && j != 0) ? (j-1)/2 : j-1;
        }

        

    }



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