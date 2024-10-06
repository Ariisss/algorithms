#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int ITERATIONS = 0;
int SWAPS = 0;
int RECURSIONS = 0;
int SHIFTS = 0;

typedef struct node
{
    struct node *next;
    int val;
} *LIST;

typedef struct
{
    int *arr;
    int count;
} ARRAY;

// Gnome Sort
void gnomeSort(ARRAY list);
// Radix Sort
void radixSort(ARRAY list);
void radixCountingSort(ARRAY list, int digitPlace);
// Bucket Sort
void bucketSort(ARRAY list);
int getBucketIndex(int val, int min, float range);
void displayBuckets(LIST bucket[]);
// Merge Sort
void mergeSort(ARRAY list, int leftNdx, int rightNdx);
void merge(ARRAY list, int leftNdx, int middleNdx, int rightNdx);
// Counting Sort
int *countSort(ARRAY list);
// Quicksort (Lomuto)
void lomutoQuicksort(ARRAY list, int low, int high);
int lomutoPartition(ARRAY list, int low, int high);
// Quicksort (Hoare)
void hoareQuicksort(ARRAY *list, int low, int high);
int hoarePartition(ARRAY *list, int low, int high);
// Strand Sort
int* strandSort(ARRAY *list);
void mergeStrandOutput(int *output, int *outputSize, int *strand, int strandSize);

// helper functions
void printArray(int arr[], int N);
void swap(int *a, int *b);

int main(){

    int values[] = {7, 123, 45, 9, 56, 210, 34, 3, 3, 150};

    ARRAY list;
    list.arr = malloc(sizeof(int) * MAX);
    list.count = 0;

    if(list.arr != NULL){
        int i;
        for(i = 0; i < MAX; i++){
            list.arr[i] = values[i];
            list.count++;
        }
    }

    // gnomeSort(list);
    int *output = countSort(list);

    printArray(output, MAX);
    // printArray(list.arr, MAX);
}

// Gnome Sort process
// 1) loop while i is less than size-1 (to avoid accessing out of bounds like when i = size - 1 and when we access i + 1 it will be out of bounds)
// 2) if the current index's value and the next to it is unsorted, we swap then move backwards (we only move backwards when i > 0)
// 3) if sorted, move forward
void gnomeSort(ARRAY list){

    int i = 0;
    while(i < list.count - 1){
        if(list.arr[i] > list.arr[i+1]){
            int temp = list.arr[i];
            list.arr[i] = list.arr[i+1];
            list.arr[i+1] = temp;
            if(i > 0){
                i--;
            }
        }else{
            i++;
        }
    }
}

// Radix Sort process
// 1) Find largest element in the array
// 2) Get the number of digits we have to iterate over by using the largest element
// 2) Iterate through each digit and sort them according to their digit for each iteration (use any stable sort), for this time, i will be using counting sort.
void radixSort(ARRAY list){

    // int i, max = list.arr[0];
    // for(i = 1; i < MAX; i++){
    //     if(list.arr[i] > max){
    //         max = list.arr[i];
    //     }
    // }

}

// Bucket Sort process
// 1) create initial bucket array (array of list nodes) with the same size as the original array
// 2) compute for range = (max-min)/bucket_size
// 3) compute for bucket_index = (elem-min)/range
// 4) place each element in the bucket with bucket_index as index (insert first or insert sorted)
// 5) take each element starting from bucket index 0 and overwrite original array (delete first)
void bucketSort(ARRAY list){



}

int getBucketIndex(int val, int min, float range){

}

void displayBuckets(LIST bucket[]){

}

// Merge Sort process
// 1) initialize leftNdx (leftmost index) and rightNdx (MAX-1)
// 2) if leftNdx < rightNdx, we get the middle index with formula [leftNdx + (rightNdx - 1) / 2]
// 3) divide/make 2 sub arrays, left size is leftNdx to middle, right size is middle + 1 to rightNdx
// 4) repeat 1 until each sub array only has 1 element
// 5) merge the sub arrays
void mergeSort(ARRAY list, int leftNdx, int rightNdx){

}

void merge(ARRAY list, int leftNdx, int middleNdx, int rightNdx){

}

// Counting Sort process
// 1) Determine the range of input data by finding the maximum value and minimum value (max - min + 1).
// 2) Initialize a count array with size equal to the range, filled with zeros.
// 3) Traverse the input array and increment the corresponding index in the count array for each element.
// 4) Modify the count array by adding the previous counts to accumulate positions.
// 5) Initialize an output array of the same size as the input array.
// 6) Traverse the input array in reverse, placing each element into its correct position in the output array based on the count array.
int *countSort(ARRAY list){

    int i, max = list.arr[0], min = list.arr[0];
    int *output = malloc(sizeof(int) * list.count);

    for(i = 1; i < MAX; i++){
        if(max < list.arr[i]){
            max = list.arr[i];
        }
        if(min > list.arr[i]){
            min = list.arr[i];
        }
    }

    int range = max - min + 1;
    int *countArray = calloc(range, sizeof(int));

    for(i = 0; i < MAX; i++){
        countArray[list.arr[i] - min]++;
    }


    for(i = 1; i < range; i++){
        countArray[i] += countArray[i-1];
    }

    for(i = list.count-1; i >= 0; i--){
        output[--countArray[list.arr[i] - min]] = list.arr[i];
    }

    // printArray(output, list.count);
    return output;
}

// Quicksort (Lomuto)
// 1) Choose the last element as the pivot.
// 2) Initialize a pointer for the smaller element.
// 3) Traverse the array, and for each element, if it is less than or equal to the pivot, swap it with the element at the smaller element pointer and increment the pointer.
// 4) After traversal, swap the pivot with the element at the smaller element pointer.
// 5) Recursively apply quick sort to the subarrays before and after the pivot.
void lomutoQuicksort(ARRAY list, int low, int high){

}

int lomutoPartition(ARRAY list, int low, int high){

}

// Quicksort (Hoare)
// 1) Choose the first element as the pivot.
// 2) Initialize two pointers, one starting just after the pivot and the other at the end of the array.
// 3) Move the left pointer forward until an element greater than or equal to the pivot is found.
// 4) Move the right pointer backward until an element less than or equal to the pivot is found.
// 5) If the left pointer is less than the right pointer, swap the elements and repeat steps 3-5.
// 6) Once pointers cross, recursively apply quick sort to the subarrays before and after the partition index.
void hoareQuicksort(ARRAY *list, int low, int high){

}

int hoarePartition(ARRAY *list, int low, int high){

}

// Strand Sort
// 1) Initialize an empty sorted list.
// 2) While the input list is not empty:
//    a) Initialize a sublist with the first element of the input list.
//    b) Traverse the input list and append to the sublist any element that is greater than the last element in the sublist.
//    c) Remove the appended elements from the input list.
//    d) Merge the sublist into the sorted list in the correct order.
// 3) Repeat until the input list is empty.
int* strandSort(ARRAY *list){

}

void mergeStrandOutput(int *output, int *outputSize, int *strand, int strandSize){

}

void printArray(int arr[], int N){

    printf("# of Iterations: %d\n", ITERATIONS);
    printf("# of Swaps: %d\n", SWAPS);
    printf("# of Shifts: %d\n", SHIFTS);
    printf("# of Recursions: %d\n", RECURSIONS);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
	*a = *b;
	*b = temp;
}