#include <stdio.h>
#include <stdlib.h>
int RECURSIONS = 0;

typedef struct
{
    int *elems;
    int count;
} ARRAY;

// 1) initialize leftNdx (leftmost index) and rightNdx (MAX-1)
// 2) if leftNdx < rightNdx, we get the middle index with formula [leftNdx + (rightNdx - 1) / 2]
// 3) divide/make 2 sub arrays, left size is leftNdx to middle, right size is middle + 1 to rightNdx
// 4) repeat 1 until each sub array only has 1 element
// 5) merge the sub arrays

void mergeSort(int *arr, int leftNdx, int rightNdx);
void merge(int *arr, int leftNdx, int middleNdx, int rightNdx);
void swap(int *x, int *y);
void printArray(int arr[], int N);

int main()
{

    int arr[] = {24, 6, 5, 2, 16, 11, 3};
    printArray(arr, 7);

    mergeSort(arr, 0, 6);

    printArray(arr, 7);

    return 0;
}

void mergeSort(int *arr, int leftNdx, int rightNdx)
{
    if (leftNdx < rightNdx)
    {
        // calculate middle index
        int middleNdx = (leftNdx + (rightNdx - 1)) / 2;

        // left subarray (not rlly another actual array) would be from left index to middle
        mergeSort(arr, leftNdx, middleNdx);

        // right subarray
        mergeSort(arr, middleNdx + 1, rightNdx);

        // after each subdividing recursion ends, we apply merging
        merge(arr, leftNdx, middleNdx, rightNdx);
        RECURSIONS++;
    }
}

void merge(int *arr, int leftNdx, int middleNdx, int rightNdx)
{

    int i, j, k;

    // get size for left temp array
    int leftSize = middleNdx - leftNdx + 1;

    // same goes for right temp array
    int rightSize = rightNdx - middleNdx;

    // initialize temporary arrays
    int *leftArr = malloc(sizeof(int) * leftSize);
    int *rightArr = malloc(sizeof(int) * rightSize);

    // copy left sub-array elements to the left temporary array
    for (i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[leftNdx + i];
    }

    // copy right sub-array elements to the right temp array
    for (i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[middleNdx + i + 1];
    }

    // initialize 3 pointers, i for the left temp array, j for the right temp array, k for overwriting the original array
    i = 0, j = 0, k = leftNdx;

    // in each iteration, the smaller element from the corresponding index of left/right temp arrays will be moved to the original array
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    // copy remaining elements
    while (i < leftSize)
    {
        arr[k++] = leftArr[i++];
    }

    // copy remaining elements
    while (j < rightSize)
    {
        arr[k++] = rightArr[j++];
    }

    // free temporary arrays
    free(leftArr);
    free(rightArr);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int N)
{
    int i;
    printf("\nRECURSIONS: %d\n", RECURSIONS);
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
