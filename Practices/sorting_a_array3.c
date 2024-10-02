#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define INF 9999

int ITERATIONS = 0;

// 1) Selection Sort
void selectionSort(int *arr);
// 2) Bubble Sort
void bubbleSort(int *arr);
// 3) Insertion Sort
void insertionSort(int *arr);
// 4) Heapsort Sort (Ascending)
void heapSort(int *heap);
int *heapifyArray(int *arr);
void maxHeapify(int *arr, int root);
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
    // shellSort(arr);
    // combSort(arr);
    tournamentSort(arr);

    // int *heap = heapifyArray(arr);
    // heapSort(heap);

    // printArray(heap, MAX+1);
    printArray(arr, MAX);
}

void tournamentSort(int *arr){

    int heapSize = MAX * 2 - 1;
    int *heap = (int*)malloc(sizeof(int) * heapSize);

    int i, arrSize = MAX-1;

    for(i = heapSize - 1; i >= 0; i--){
        heap[i] = arrSize >= 0 ? arr[arrSize--] : INF;
    }

    int startNdx = heapSize - 1;

    for(i = 0; i < MAX; i++){

        for(int j = (startNdx-1) / 2; j >= 0; ){
            
            int RC = j * 2 + 1;
            int LC = RC + 1;

            int left = LC < (heapSize/2) ? heap[LC] : LC;
            int right = RC < (heapSize/2) ? heap[RC] : RC;

            heap[j] = heap[left] < heap[right] ? left : right;

            j = (i > 0 && j != 0) ? (j-1) / 2 : j - 1;

        } 

        startNdx = heap[0];
        arr[i] = heap[startNdx];
        heap[startNdx] = INF;

    }

}

void combSort(int *arr)
{

    int i, gap, swapped = 1;

    gap = MAX / 1.3;

    while (gap >= 1 || swapped)
    {

        int pairs = MAX - gap;
        swapped = 0;

        for (i = 0; i < pairs; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
            }
        }
        ITERATIONS++;
        gap /= 1.3;
    }
    printf("iterations: %d\n", ITERATIONS);
}

void shellSort(int *arr)
{

    int i, j, gap, key;

    gap = MAX / 2;
    int swapped = 1;

    while (gap != 1 || swapped)
    {

        swapped = 0;

        for (i = gap; i < MAX; i++)
        {
            key = arr[i];
            for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
            {
                arr[j] = arr[j - gap];
                swapped = 1;
            }
            arr[j] = key;
        }

        gap /= 2;
    }
}

void insertionSort(int *arr)
{

    int i, j, key;

    for (i = 0; i < MAX; i++)
    {
        key = arr[i];
        for (j = i; j >= 0 && arr[j - 1] > key; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = key;
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
            }
        }
    }
}

void selectionSort(int *arr)
{

    int i, j;
    for (i = 0; i < MAX; i++)
    {
        int min = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void printArray(int arr[], int N)
{

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