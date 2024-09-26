#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int *elems;
    int count;
} ARRAY;

int *countSort(ARRAY *arr);
void printArray(int arr[], int N);

int main()
{

    ARRAY arr;
    arr.elems = (int *)malloc(sizeof(int) * MAX);
    arr.count = 0;

    int values[] = {8, 2, 7, 5, 0, 9, 1, 2, 5, 3};

    int i;
    for (i = 0; i < MAX; i++)
    {
        arr.elems[i] = values[i];
        arr.count++;
    }

    int *output = countSort(&arr);
    printArray(output, MAX);
}

int *countSort(ARRAY *arr)
{

    int i;
    int *output = (int *)calloc(MAX, sizeof(int));

    // 1) find max element
    int max = -1;
    for (i = 0; i < arr->count; i++)
    {
        if (arr->elems[i] > max)
        {
            max = arr->elems[i];
        }
    }

    // 2) create count array (0 - max)
    int *countArray = (int *)calloc(max, sizeof(int));

    // 3) add element count/frequency
    for (i = 0; i < arr->count; i++)
    {
        countArray[arr->elems[i]]++;
    }

    // 4) turn countArray to prefix sum
    for (i = 0; i < max; i++)
    {
        countArray[i + 1] += countArray[i];
    }

    // 5) fill the output array
    for (i = arr->count - 1; i >= 0; i--)
    {
        output[--countArray[arr->elems[i]]] = arr->elems[i];
    }

    return output;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}