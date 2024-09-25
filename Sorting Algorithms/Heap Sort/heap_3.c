// This version implements recursive version of heapify with the 0th index as the last index counter.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
} *HEAP;

void swap(int *a, int *b);
void heapify(HEAP heap, int i);
void heapSort(int *arr, int max);

int main()
{
    int array[] = {12, 11, 13, 5, 6, 7, 2, 5, 15, 1, 0};
    int N = sizeof(array) / sizeof(array[0]);

    HEAP heap = (HEAP)malloc(sizeof(HEAP));

    if (heap != NULL)
    {
        heap->arr = (int *)malloc(sizeof(int) * (N+1));
        heap->arr[0] = 0;
    }

    int i;

    for(i = 0; i < N; i++){
        heap->arr[i+1] = array[i];
        heap->arr[0]++;
    }

    for(i = heap->arr[0] / 2; i > 0; i--){
        heapify(heap, i);
    }

    for(i = 1; i <= heap->arr[0]; i++){
        printf("%d ", heap->arr[i]);
    }


}

void heapify(HEAP heap, int i)
{

    int lowNdx = i;
    int LC = i * 2;
    int RC = i * 2 + 1;

    if(LC <= heap->arr[0] && heap->arr[LC] < heap->arr[lowNdx]){
        lowNdx = LC;
    }

    if(RC <= heap->arr[0] && heap->arr[RC] < heap->arr[lowNdx]){
        lowNdx = RC;
    }

    if(lowNdx != i){
        swap(&heap->arr[lowNdx], &heap->arr[i]);
        heapify(heap, lowNdx);
    }

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
