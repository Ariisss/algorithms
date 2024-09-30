#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define INF 9999

int SWAPS = 0;
int ITERATIONS = 0;
int SHIFTS = 0;

// 1) Selection Sort
void selectionSort(int *arr);
// 2) Bubble Sort
void bubbleSort(int *arr);
// 3) Insertion Sort
void insertionSort(int *arr);
// 4) Heapsort Sort (Descending with heap[0] as last index)
void heapSort(int *arr);
void minHeapify(int *arr, int max, int ndx);
// 5) Shell Sort
void shellSort(int *arr);
// 6) Comb Sort
void combSort(int *arr);
// 7) Tournament Sort
void tournamentSort(int *arr);

// Util Functions
void printArray(int arr[], int size);
void swap(int *a, int *b);

int main()
{

    int arr[] = {27, 14, 89, 3, 56, 42, 18, 75, 9, 33};

    // selectionSort(arr);
    // bubbleSort(arr);
    // insertionSort(arr);
    // heapSort(arr);
    // shellSort(arr);
    // combSort(arr);
    // tournamentSort(arr);

    printArray(arr, MAX);
}

void shellSort( int *arr){
    
}

void insertionSort(int *arr)
{

    int i, j, value;
    for (i = 1; i < MAX; i++)
    {
        value = arr[i];
        for (j = i; j > 0 && arr[j-1] > value; j--)
        {
            arr[j] = arr[j - 1];
            SHIFTS++;
            ITERATIONS++;
        }
        ITERATIONS++;
        arr[j] = value;
    }
    
}

void bubbleSort(int *arr)
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                SWAPS++;
            }
            ITERATIONS++;
        }
    }
}

void selectionSort(int *arr)
{

    int i, j, min;
    for (i = 0; i < MAX; i++)
    {
        min = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            ITERATIONS++;
        }

        if (min != i)
        {
            swap(&arr[min], &arr[i]);
            SWAPS++;
        }
    }
}

void printArray(int arr[], int N)
{

    printf("# of Iterations: %d\n", ITERATIONS);
    printf("# of Swaps: %d\n", SWAPS);
    printf("# of Shifts: %d\n", SHIFTS);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}