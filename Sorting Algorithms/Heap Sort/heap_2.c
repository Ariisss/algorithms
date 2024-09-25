// This heapsort version implements a non recursive method for heapify and usage of deleteMin/Max for heapsorting

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int heapSize;
} HEAP;

void swap(int *a, int *b);
void printArray(int arr[], int N);
void minHeapify(HEAP *heap);
void maxHeapify(HEAP *heap);
void deleteMin(HEAP *heap);
void deleteMax(HEAP *heap);
void minHeapSort(HEAP *heap);
void maxHeapSort(HEAP *heap);

int main()
{

    int arr[] = {9, 11, 13, 0, 17, 4, 8, 2, 1, 0, 20};
    int N = sizeof(arr) / sizeof(arr[0]);

    HEAP heap;
    heap.arr = (int *)malloc(sizeof(int) * N);
    heap.heapSize = N;

    int i, j;
    for (i = 0; i < N; i++)
    {
        heap.arr[i] = arr[i];
    }

    // printf("heapsize: %d\n", heap.heapSize);
    // printf("Unsorted Array: ");
    // printArray(heap.arr, heap.heapSize);

    // minHeapify(&heap);
    // minHeapSort(&heap);
    maxHeapify(&heap);
    maxHeapSort(&heap);

    // printf("\nMINHEAP: ");
    printArray(heap.arr, heap.heapSize);
}

void maxHeapSort(HEAP *heap)
{

    int heapSize = heap->heapSize;
    int i;
    for (i = heap->heapSize; i > 0; i--)
    {
        deleteMax(heap);
    }
    heap->heapSize = heapSize;
}

void deleteMax(HEAP *heap)
{

    swap(&heap->arr[0], &heap->arr[heap->heapSize - 1]);
    heap->heapSize--;
    maxHeapify(heap);
}

void maxHeapify(HEAP *heap)
{

    if (heap->heapSize > 0)
    {

        int i, j;
        for (i = heap->heapSize - 1; i >= 0; i--)
        {

            int curr = i;
            int heapifyFlag = 1;

            while (heapifyFlag == 1)
            {

                int highNdx = curr;
                int LC = highNdx * 2 + 1;
                int RC = highNdx * 2 + 2;

                if (LC < heap->heapSize && heap->arr[LC] > heap->arr[highNdx])
                {
                    highNdx = LC;
                }

                if (RC < heap->heapSize && heap->arr[RC] > heap->arr[highNdx])
                {
                    highNdx = RC;
                }

                if (highNdx != curr)
                {
                    swap(&heap->arr[highNdx], &heap->arr[curr]);
                    curr = highNdx;
                    heapifyFlag = 1;
                }
                else
                {
                    heapifyFlag = 0;
                }
            }
        }
    }
}

void minHeapSort(HEAP *heap)
{

    int heapSize = heap->heapSize, i;
    for (i = heap->heapSize; i > 0; i--)
    {
        deleteMin(heap);
    }

    heap->heapSize = heapSize;
}

void minHeapify(HEAP *heap)
{

    if (heap->heapSize > 0)
    {
        int i, j, heapifyFlag;

        for (i = heap->heapSize - 1; i >= 0; i--)
        {

            int curr = i;
            heapifyFlag = 1;

            while (heapifyFlag)
            {

                int lowNdx = curr;
                int LC = lowNdx * 2 + 1;
                int RC = lowNdx * 2 + 2;

                if (LC < heap->heapSize && heap->arr[LC] < heap->arr[lowNdx])
                {
                    lowNdx = LC;
                }

                if (RC < heap->heapSize && heap->arr[RC] < heap->arr[lowNdx])
                {
                    lowNdx = RC;
                }

                if (lowNdx != curr)
                {
                    swap(&heap->arr[curr], &heap->arr[lowNdx]);
                    heapifyFlag = 1;
                    curr = lowNdx;
                }
                else
                {
                    heapifyFlag = 0;
                }
            }
        }
    }
}

void deleteMin(HEAP *heap)
{

    int temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->heapSize - 1];
    heap->arr[heap->heapSize - 1] = temp;
    heap->heapSize--;
    minHeapify(heap);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}
