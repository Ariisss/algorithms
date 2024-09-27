#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10
typedef struct node
{
    struct node *next;
    int val;
} *list;

void printArray(int arr[], int N);
void bucketSort(int *arr);
int getBucketIndex(int val, int min, float range);
void displayBuckets(list bucket[]);

int main()
{

    int arr[] = {12, 11, 13, 5, 6, 7, 2, 5, 15, 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr);

    printf("\nSorted array: ");
    printArray(arr, MAX);
    
}

// 1) create initial bucket array (array of list nodes) with the same size as the original array
// 2) compute for range = (max-min)/bucket_size
// 3) compute for bucket_index = (elem-min)/range
// 4) place each element in the bucket with bucket_index as index (insert first or insert sorted)
// 5) take each element starting from bucket index 0 and overwrite original array (delete first)

void bucketSort(int *arr)
{

    // list *bucket = (list *)malloc(sizeof(list) * MAX);
    list *bucket = calloc(MAX, sizeof(list));

    int min = arr[0], max = arr[0], i;
    for (i = 0; i < MAX; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int range = ceil((float)(max - min) / (float)MAX);

    printf("range is %d\n\n", range);

    for (i = 0; i < MAX; i++)
    {
        int ndx = getBucketIndex(arr[i], min, range);
        list *ptr = &bucket[ndx];

        for (; (*ptr) != NULL && arr[i] > (*ptr)->val; ptr = &(*ptr)->next){}

        list temp = malloc(sizeof(struct node));
        if (temp != NULL)
        {
            temp->val = arr[i];
            temp->next = *ptr;
            (*ptr) = temp;
        }
    }

    for(i = 0; i < MAX; ){

        list temp = NULL;
        int j;

        for(j = 0; j < MAX; j++){
            list *ptr = &bucket[j];
            for( ; (*ptr) != NULL; ptr = &(*ptr)->next){
                arr[i++] = (*ptr)->val;
            }
        }

    }

    displayBuckets(bucket);

}

void displayBuckets(list bucket[])
{

    int i;
    list trav;

    for (i = 0; i < MAX; i++)
    {
        printf("\nBucket %d: ", i + 1);
        for (trav = bucket[i]; trav != NULL; trav = trav->next)
        {
            printf("%d ", trav->val);
        }
    }
}

int getBucketIndex(int val, int min, float range)
{
    return (val - min) / range;
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
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}