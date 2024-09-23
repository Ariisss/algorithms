#include <stdio.h>

void swap(int *a, int *b);
void heapify(int *arr, int max, int i);
void heapSort(int *arr, int max);
void printArray(int arr[], int N);

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 5, 15 , 1, 0 };
    int N = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}

// max is the max size of the array and i is the current parent
void heapify(int *arr, int max, int i){

    // high holds the index of the largest element since this is a max heap
    int high = i;
    
    // index of left child
    int leftChild = i * 2 + 1;

    //index of right child
    int rightChild = i * 2 + 2;

    // if left child is greater than parent, high index becomes the left child index
    if(leftChild < max && arr[leftChild] > arr[high]){
        high = leftChild;
    }

    // the same as left child logic
    if(rightChild < max && arr[rightChild] > arr[high]){
        high = rightChild;
    }

    // if the high index changed (a child is greater than the initial root/parent node), we swap both then heapify with the current high as the parent/root node.
    if(high != i){
        swap(&arr[i], &arr[high]);
        heapify(arr, max, high);
    }

}

void heapSort(int *arr, int max){

    int i, j;
    // building a max heap tree starting from the lowest level parent
    for(i = max/2 - 1; i >= 0; i--){
        heapify(arr, max, i);
    }

    // delete first and heapifying starting from the root node (index 0)
    for(i = max - 1; i >= 0; i--){
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
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