#include <stdio.h>

void printArray(int arr[], int N);
void swap(int *a, int *b);
void shellSort(int *arr, int N);

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 5, 15 , 1, 0 };
    int N = sizeof(arr) / sizeof(arr[0]);

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