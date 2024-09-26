#include <stdio.h>
#include <stdlib.h>

void gnomeSort(int *arr, int size);
void printArray(int arr[], int N);
void swap(int *a, int *b);

int main(){

    int arr[] = {8, 6, 4, 9, 0, 1, 2, 6, 3, 9, 2, 0, 12, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    gnomeSort(arr, size);

    int i;
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void gnomeSort(int *arr, int size){

    int i = 0;

    // loop until size - 1 (to avoid accessing out of bounds like when i = size - 1 and when we access i + 1 it will be invalid).
    while(i < size - 1){

        // if the current index's value and the next to it is unsorted, we swap then move backwards
        // P.S: Move only when i > 0
        if(arr[i] > arr[i+1]){
            swap(&arr[i], &arr[i+1]);
            if(i > 0){
                i--;
            }
        }else{
            // if it's already sorted, we move forward
            i++;
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