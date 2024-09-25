#include <stdio.h>
#include <stdlib.h>
#define INF 9999999

void printArray(int arr[], int N);
void swap(int *a, int *b);
void tournaSort(int *arr, int size);

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 5, 15 , 1, 0 };
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Initial Array: \n");
    printArray(arr, N);

    tournaSort(arr, N);

    printf("\n\nSorted Array: \n");
    printArray(arr, N);

    return 0;
}

void tournaSort(int *arr, int size){

    // initialize heapSize to accomodate the original array elements as leaves of the tree (size * 2 - 1)
    int heapSize = (size * 2 - 1);

    // allocate memory for the heap
    int* heap = (int*)malloc(heapSize * sizeof(int));

    int i, j, x = heapSize;
    int startNdx = heapSize - 1;

    // copy the original array's elements to the heap starting from the last element
    for(i = size - 1; i >= 0; i--){
        heap[x - 1] = arr[i];
        x--;
    }

    // loop for each element of the original array, every iteration, one element will be
    // overwritten to its rightful place depending if it's a loser tree or a winner tree
    for(i = 0; i < size; i++){

        // this loop decides the winner, we start with the lowest level parent on first iteration,
        // then the winner's parent on the next iterations.
        for(j = (startNdx-1)/2; j >= 0;){
            
            // LC is leftchild index, RC is rightchild index
            int LC = (j*2) + 1;
            int RC = (j*2) + 2;


            // Since we purposely initialized the heap with double the size - 1 to make sure the
            // original elements are leaf nodes, we can use the formula of heapsize-size to check
            // if the child is a leaf or not.

            // If the child is a leaf, we initialize right or left as the child's value, and if it's
            // not a leaf, we then assign the index value inside the child to right or left.

            int left = LC < heapSize - size ? heap[LC] : LC;
            int right = RC < heapSize - size ? heap[RC] : RC;

            // We store the lower value since this is a min tree
            heap[j] = heap[left] < heap[right] ? left : right;

            //If we're on the first iteration, for each parent we will be doing the comparison for the winner (j-1).

            // But if we're on the second iteration where (i > 0), then that means we already have one winner.
            // Since we replaced the winning index's value with INF, we then redo the logic in looking for
            // winners but skip everything except the winning index's path.
            j = (i > 0 && j != 0) ? (j-1)/2 : j-1;
        
        }

        // We set the next start index as the winning index, so for the next iteration of the inner loop,
        // we will be at the winner's parent.
        startNdx = heap[0];

        // Overwrite the original array with every winner
        arr[i] = heap[startNdx];

        // Change the value of the winning node with INF so it won't win again
        heap[startNdx] = INF;  
    }

    // free the allocated memory after use
    free(heap);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }

}