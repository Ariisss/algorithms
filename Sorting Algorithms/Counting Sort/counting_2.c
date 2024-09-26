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

    int values[] = {8, 2, 7, -5, 0, 9, 1, 2, -1, 3};

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
    int *output = (int *)calloc(MAX, sizeof(int));
    int i, min = arr->elems[0], max = arr->elems[0];

    // 1) get maximum and minimum value
    for (i = 0; i < MAX; i++)
    {
        if (arr->elems[i] > max)
        {
            max = arr->elems[i];
        }

        if (arr->elems[i] < min)
        {
            min = arr->elems[i];
        }
    }
    
    printf("\nmin: %d\n", min);


    // 2) create count array with max - min size
    int *countArray = (int *)calloc(max - min + 1, sizeof(int));

    // 3) add element count/frequency
    for (i = 0; i < MAX; i++)
    {
        countArray[arr->elems[i] - min]++;
    }

    // 4) turn countArray to prefix sum
    for (i = 0; i < (max - min); i++)
    {
        countArray[i + 1] += countArray[i];
    }

    // 5) fill the output array
    for (i = MAX - 1; i >= 0; i--)
    {
        output[--countArray[arr->elems[i] - min]] = arr->elems[i];
    }

    return output;
}

void printArray(int arr[], int N)
{	
	int i;
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}
