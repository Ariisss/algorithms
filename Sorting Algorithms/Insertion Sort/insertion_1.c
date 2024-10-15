#include <stdio.h>

void insertionSort(int *arr, int size);

int main()
{

    int array[] = {5, 2, 9, 6, 1, 3};
    int size = sizeof(array) / sizeof(array[0]);

    insertionSort(array, size);

    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

void insertionSort(int *arr, int size)
{

    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}