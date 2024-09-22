#include <stdio.h>

void swap(int *a, int *b);
void heapify(int *arr, int max, int i);
void heapSort(int *arr, int N);
void printArray(int arr[], int N);

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}

void heapify(int *arr, int max, int i){

    int high = i;
    int leftChild = i * 2 + 1;
    int rightChild = i * 2 + 2;

    if(leftChild < max && arr[leftChild] > arr[high]){
        high = leftChild;
    }

    if(rightChild < max && arr[leftChild] > arr[high]){
        high = rightChild;
    }

    if(high != i){
        swap(&arr[i], &arr[high]);
        heapify(arr, max, high);
    }

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
