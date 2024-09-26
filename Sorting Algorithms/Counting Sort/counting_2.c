#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int *elems;
    int count;
} ARRAY;

int* countSort(ARRAY *arr);
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

    int* output = countSort(&arr);
    printArray(output, MAX);
}

int* countSort(ARRAY *arr)
{
    int* output = (int*)calloc(MAX, sizeof(int));

    return output;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}