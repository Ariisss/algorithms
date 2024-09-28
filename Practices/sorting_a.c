#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

// 1) Selection Sort
void selectionSort(int *arr);
// 2) Bubble Sort
void bubbleSort(int *arr);
// 3) Insertion Sort
void insertionSort(int *arr);
// 4) Heapsort Sort
void heapSort(int *arr);
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

    selectionSort(arr);

    printArray(arr, MAX); 

}

void selectionSort(int *arr)
{

    int min, i, j;
    for (i = 0; i < MAX; i++)
    {
        min = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}