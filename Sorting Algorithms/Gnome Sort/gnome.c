#include <stdio.h>
#include <stdlib.h>

void gnomeSort(int *arr, int size);
void printArray(int arr[], int N);
void swap(int *a, int *b);

int main(){

    int size = 10;
    int arr[] = {8, 6, 4, 9, 0, 1, 2, 6, 3, 9};

    gnomeSort(arr, size);

    int i;
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void gnomeSort(int *arr, int size){

    int i = 0;

    while(i < size - 1){
        if(arr[i] > arr[i+1]){
            swap(&arr[i], &arr[i+1]);
            if(i > 0){
                i--;
            }
        }else{
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