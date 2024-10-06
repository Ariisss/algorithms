// This version of tournament sort passes values instead of indices in the heap

#include <stdio.h>
#include <stdlib.h>
#define INF 9999999
typedef struct
{
    int *arr;
    int lastNdx;
} *HEAP;

void printArray(int arr[], int N);
void swap(int *a, int *b);
void tournaSort(HEAP heap, int *arr);

int main()
{

    int arr[] = {12, 11, 13, 5, 6, 7, 2, 5, 15, 1, 0};
    int N = sizeof(arr) / sizeof(arr[0]);

    int heapSize = (2 * N) - 1;
    HEAP heap = (HEAP)malloc(sizeof(HEAP));

    if (heap != NULL)
    {
        heap->arr = (int *)malloc(sizeof(int) * heapSize);
        heap->lastNdx = -1;
    }

    int i;
    for (i = heapSize - 1; i >= 0; i--)
    {
        heap->lastNdx++;
        heap->arr[i] = N > 0 ? arr[N - 1] : INF;
        N--;
    }

    printf("Initial Array: \n");
    printArray(heap->arr, heap->lastNdx);

    printf("\nlast index: %d\n", heap->lastNdx);

    // tournaSort(heap, arr);

    printf("\n\nSorted Array: \n");
    printArray(heap->arr, heap->lastNdx);

    return 0;
}

// 1. For each element in the original array, we loop then overwrite the array
// 2. Another loop to get the winner
        // 2.1) Get left child and right child
        // 2.2) If
// 3. 
// 4. 

void tournaSort(HEAP heap, int *arr)
{

    if (heap->lastNdx > 0)
    {

        int size = sizeof(arr) / sizeof(arr[0]);
        int i, j, startNdx = heap->lastNdx;

        // loop for each element in original array
        for (i = 0; i < size; i++)
        {
            int minNdx = startNdx;
            for (j = (startNdx - 1) / 2; j >= 0;)
            {

                int LC = j * 2 + 1;
                int RC = LC + 1;
                int low = j;

                low = heap->arr[LC] < heap->arr[RC] ? LC : RC;

            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i <= N; i++)
    {
        printf("%d ", arr[i]);
    }
}