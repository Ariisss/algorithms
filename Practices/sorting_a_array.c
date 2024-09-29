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
// 4) Heapsort Sort (Ascending)
void heapSort(int *arr);
void maxHeapify(int *arr, int max, int ndx);
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

void tournamentSort(int *arr)
{

    int heapSize = MAX * 2 - 1;
    int heap[MAX * 2 - 1];
    // printf("%d", heapSize);

    int i, j = MAX - 1;
    for (i = heapSize - 1; i >= 0; i--, j--)
    {
        heap[i] = j >= 0 ? arr[j] : INF;
    }
    // printArray(arr, MAX);
    // printArray(heap, heapSize);
    int startNdx = heapSize - 1;

    for (i = 0; i < MAX; i++)
    {

        for (j = (startNdx - 1) / 2; j >= 0;)
        {

            int LC = j * 2 + 1;
            int RC = LC + 1;

            int left = LC < heapSize / 2 ? heap[LC] : LC;
            int right = RC < heapSize / 2 ? heap[RC] : RC;

            heap[j] = heap[left] < heap[right] ? left : right;
            
            ITERATIONS++;

            j = (i > 0 && j != 0) ? (j - 1) / 2 : j - 1;
        }

        startNdx = heap[0];
        arr[i] = heap[startNdx];
        heap[startNdx] = INF;
        SWAPS++;
    }
}

void combSort(int *arr)
{

    int i, j, gap;
    int swapped = 1;

    while (gap != 1 || swapped == 1)
    {

        gap /= 1.3;

        if (gap < 1)
        {
            gap = 1;
        }

        swapped = 0;

        for (i = 0; i + gap < MAX; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
                SWAPS++;
            }
            ITERATIONS++;
        }
    }
}

void shellSort(int *arr)
{

    int i, j, gap;

    for (gap = MAX / 2; gap > 0; gap /= 2)
    {

        for (i = gap; i < MAX; i++)
        {

            int key = arr[i];
            for (j = i; j >= gap && key < arr[j - gap]; j -= gap)
            {
                arr[j] = arr[j - gap];
                ITERATIONS++;
                SHIFTS++;
            }

            ITERATIONS++;
            arr[j] = key;
        }
    }
}

void heapSort(int *arr)
{

    int i;
    for (i = (MAX - 1) / 2; i >= 0; i--)
    {
        maxHeapify(arr, MAX, i);
    }

    for (i = MAX - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void maxHeapify(int *arr, int max, int ndx)
{

    int high = ndx;
    int LC = ndx * 2 + 1;
    int RC = LC + 1;

    if (LC < max && arr[LC] > arr[high])
    {
        high = LC;
    }

    if (RC < max && arr[RC] > arr[high])
    {
        high = RC;
    }

    if (high != ndx)
    {
        swap(&arr[high], &arr[ndx]);
        maxHeapify(arr, max, high);
    }
}

void insertionSort(int *arr)
{
    int i, j, key;

    for (i = 0; i < MAX; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
            ITERATIONS++;
            SHIFTS++;
        }
        ITERATIONS++;
        arr[j + 1] = key;
    }
}

void bubbleSort(int *arr)
{

    int i, j;
    for (i = 0; i < MAX; i++)
    {
        ITERATIONS++;
        for (j = 0; j < MAX - i - 1; j++)
        {
            ITERATIONS++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                SWAPS++;
            }
        }
    }
}

void selectionSort(int *arr)
{

    int min, i, j;
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
        ITERATIONS++;
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