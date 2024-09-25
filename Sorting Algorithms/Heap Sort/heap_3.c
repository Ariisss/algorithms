// This version implements recursive version of min heapify with the 0th index as the last index counter.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
} *HEAP;

void swap(int *a, int *b);
void heapify(HEAP heap, int i);
void heapSort(HEAP heap);

int main()
{
    int array[] = {12, 11, 13, 5, 6, 7, 2, 5};
    int N = sizeof(array) / sizeof(array[0]);

    HEAP heap = (HEAP)malloc(sizeof(HEAP));

    if (heap != NULL)
    {
        heap->arr = (int *)malloc(sizeof(int) * (N + 1));
        heap->arr[0] = 0;
    }

    int i;

    for (i = 0; i < N; i++)
    {
        heap->arr[i + 1] = array[i];
        heap->arr[0]++;
    }

    heapSort(heap);

    printf("\nsorted array: ");
    for (i = 1; i <= heap->arr[0]; i++)
    {
        printf("%d ", heap->arr[i]);
    }
}

void heapSort(HEAP heap)
{

    int i, ctr = 1;
    for (i = heap->arr[0] / 2; i > 0; i--)
    {
        heapify(heap, i);
    }

    int lastNdx = heap->arr[0];
    for (i = heap->arr[0] + 1; i > 1; i--)
    {
        swap(&heap->arr[1], &heap->arr[i - 1]);
        heap->arr[0]--;
        heapify(heap, 1);
    }
    heap->arr[0] = lastNdx;
}

void heapify(HEAP heap, int i)
{

    int highNdx = i;
    int LC = i * 2;
    int RC = i * 2 + 1;

    if (LC <= heap->arr[0] && heap->arr[LC] > heap->arr[highNdx])
    {
        highNdx = LC;
    }

    if (RC <= heap->arr[0] && heap->arr[RC] > heap->arr[highNdx])
    {
        highNdx = RC;
    }

    if (highNdx != i)
    {
        swap(&heap->arr[highNdx], &heap->arr[i]);
        heapify(heap, highNdx);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
