// This heapsort version implements a non recursive method for heapify and usage of deleteMin/Max for heapsorting

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *arr;
    int heapSize;
} HEAP;

void swap(int *a, int *b);
void printArray(int arr[], int N);
void minHeapify(HEAP *heap);
void maxHeapify(HEAP *heap);
void deleteMin(HEAP *heap);
void deleteMax(HEAP *heap);
void heapSort(HEAP *heap);


int main(){

    int arr[] = { 12, 11, 13, 5, 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    HEAP heap;
    heap.arr = (int*)malloc(sizeof(int) * N);
    heap.heapSize = N;

    int i, j;
    for(i = 0; i < N; i++){
        heap.arr[i] = arr[i];
    }

//    swap(&heap.arr[heap.heapSize-1], &heap.arr[0]);

    printf("heapsize: %d\n", heap.heapSize);
    printf("Unsorted Array: ");
    printArray(heap.arr, heap.heapSize);

    minHeapify(&heap);

    printf("\nMINHEAP: ");
    printArray(heap.arr, heap.heapSize);

}

void minHeapify(HEAP *heap){

    if(heap->heapSize > 0){
        int i, j, heapifyFlag;

        for(i = heap->heapSize - 1; i >= 0; i--){
            
            int curr = i;
            heapifyFlag = 1;

            while(heapifyFlag){
				
                int lowNdx = curr;
                int LC = lowNdx * 2 + 1;
                int RC = lowNdx * 2 + 2;
            
                if(LC < heap->heapSize && heap->arr[LC] < heap->arr[lowNdx]){
                    lowNdx = LC;
                }

                if(RC < heap->heapSize && heap->arr[RC] < heap->arr[lowNdx]){
                    lowNdx = RC;
                }

                if(lowNdx != curr){
                    swap(&heap->arr[curr], &heap->arr[lowNdx]);
                    heapifyFlag = 1;
                    curr = lowNdx;
                }else{
                    heapifyFlag = 0;
                }
            }

            printf("\n%d iteration: ", i+1);
            printArray(heap->arr, heap->heapSize);

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
	int i;
    for (i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }

}
