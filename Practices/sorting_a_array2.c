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
void heapSort(int *heap);
int *heapifyArray(int *arr);
void minHeapify(int *arr, int root);
// 5) Shell Sort
void shellSort(int *arr);
// 6) Comb Sort
void combSort(int *arr);
// 7) Tournament Sort
void tournamentSort(int *arr);
void tournamentSort2(int *arr);

// Util Functions
void printArray(int arr[], int size);
void swap(int *a, int *b);

int main()
{

    int arr[] = {27, 14, 89, 3, 56, 42, 18, 75, 9, 33};

    // selectionSort(arr);
    // bubbleSort(arr);
    // insertionSort(arr);
    // shellSort(arr);
    // combSort(arr);
    // tournamentSort(arr);
    tournamentSort2(arr);

    // int *heap = heapifyArray(arr);
    // heapSort(heap);

    // printArray(heap, MAX+1);
    printArray(arr, MAX);
}

void tournamentSort2(int *arr){;

    int heapSize = MAX*2;
    int *heap = malloc(sizeof(int) * heapSize);
    heap[0] = heapSize-1;

    int i, j = MAX-1;
    for(i = heap[0]; i >= 1; i--){
        heap[i] = j >= 0 ? arr[j--] : INF;
    }

    printArray(heap, heapSize);
    int startNdx = (heapSize-1);

    for(i = 0; i < MAX; i++){

        for(j = startNdx/2; j >= 1; ){

            int LC = j * 2;
            int RC = LC + 1;

            int left = LC < heapSize/2 ? heap[LC] : LC;
            int right = RC < heapSize/2 ? heap[RC] : RC;

            heap[j] = heap[left] < heap[right] ? left : right;

            j = (i > 1 && j != 1) ? j/2 : j - 1;

        }

        startNdx = heap[1];
        arr[i] = heap[startNdx];
        heap[startNdx] = INF;

    }

}

void tournamentSort(int *arr)
{

    int heapSize = MAX * 2 - 1;
    int *heap = malloc(sizeof(int) * heapSize);

    int i, j = MAX - 1;
    for (i = heapSize - 1; i >= 0; i--)
    {
        heap[i] = j >= 0 ? arr[j--] : INF;
    }

    int startNdx = heapSize - 1;

    for (i = 0; i < MAX; i++)
    {

        for (j = (startNdx - 1) / 2; j >= 0;)
        {

            int LC = j * 2 + 1;
            int RC = j * 2 + 2;

            int left = LC < heapSize - MAX ? heap[LC] : LC;
            int right = RC < heapSize - MAX ? heap[RC] : RC;

            heap[j] = heap[left] < heap[right] ? left : right;

            j = (i > 0 && j != 0) ? (j - 1) / 2 : j - 1;
            ITERATIONS++;
        }
        startNdx = heap[0];
        arr[i] = heap[startNdx];
        heap[startNdx] = INF;
        SWAPS++;
    }
}

void heapSort(int *heap)
{

    int i, lastNdx = heap[0];

    for (i = heap[0]; i > 0; i--)
    {
        swap(&heap[1], &heap[i]);
        heap[0]--;
        minHeapify(heap, 1);
    }

    heap[0] = lastNdx;
}

int *heapifyArray(int *arr)
{

    int *heap = malloc(sizeof(int) * (MAX + 1));
    heap[0] = 0;
    int i;

    for (i = 0; i < MAX; i++)
    {
        heap[i + 1] = arr[i];
        heap[0]++;
    }

    for (i = heap[0] / 2; i > 0; i--)
    {
        minHeapify(heap, i);
    }

    return heap;
}

void minHeapify(int *arr, int root)
{

    int low = root;
    int LC = low * 2;
    int RC = low * 2 + 1;

    if (LC <= arr[0] && arr[LC] < arr[low])
    {
        low = LC;
    }

    if (RC <= arr[0] && arr[RC] < arr[low])
    {
        low = RC;
    }

    if (low != root)
    {
        swap(&arr[low], &arr[root]);
        minHeapify(arr, low);
    }
}

void combSort(int *arr)
{

    int gap = MAX / 1.3, i, swapped = 1;

    while (gap >= 1 || swapped)
    {

        swapped = 0;

        if (gap < 1)
        {
            gap = 1;
        }

        for (i = 0; i + gap < MAX; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
                SWAPS++;
            }
        }

        ITERATIONS++;
        gap /= 1.3;
    }
}

void shellSort(int *arr)
{

    int gap, i, j, key;

    for (gap = MAX / 2; gap > 0; gap /= 2)
    {

        for (i = gap; i < MAX; i++)
        {
            key = arr[i];

            for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
            {
                arr[j] = arr[j - gap];
                SHIFTS++;
            }
            ITERATIONS++;
            arr[j] = key;
        }
    }
}

void insertionSort(int *arr)
{

    int i, j, value;
    for (i = 1; i < MAX; i++)
    {
        value = arr[i];
        for (j = i; j > 0 && arr[j - 1] > value; j--)
        {
            arr[j] = arr[j - 1];
            SHIFTS++;
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