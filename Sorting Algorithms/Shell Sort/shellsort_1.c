#include <stdio.h>

void printArray(int arr[], int N);
void swap(int *a, int *b);
void shellSort(int *arr, int size);

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 5, 15 , 1, 0 };
    int N = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, N);
    printArray(arr, N);

}

void shellSort(int *arr, int size){

    int gap, i, j;

    for(gap = size/2; gap > 0; gap /= 2){
        for(i = gap; i < size; i++){

            int key = arr[i];
            for(j = i; j >= gap && key < arr[j-gap]; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
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