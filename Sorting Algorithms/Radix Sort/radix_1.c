#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void radixSort(int *arr);
void printArray(int arr[], int N);

int main()
{

    int arr[] = {809, 214, 45, 67, 88, 9, 102, 53, 345, 749};

    radixSort(arr);

    printArray(arr, MAX);
}

// 1) Find largest element in the array to know how many digits we have to check
// 2) Iterate through each digit and sort them according to their digit for each iteration (use any stable sort)

void radixSort(int *arr)
{

    int i, max = arr[0], j;
    for (i = 0; i < MAX; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // getting digits
    int digits = 1;
    while (max >= 10)
    {
        max /= 10;
        digits++;
    }

    // we sort them by each digit
    int ctr = 1;
    while (ctr <= digits)
    {

        int modulo = 10 * ctr;

        for (i = 1; i < MAX; i++)
        {
            int key = arr[i];
            for (j = i - 1; j >= 0 && key < arr[j];)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }

        ctr++;
    }
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}