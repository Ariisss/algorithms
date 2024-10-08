#include <stdio.h>
int ITERATIONS = 0;

void printArray(int arr[], int N);
void swap(int *a, int *b);
void shellSort(int *arr, int size);

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 5, 15 , 1, 0 };
    int N = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, N);
    printArray(arr, N);

}

void shellSort(int *arr, int size){

    int gap, i, j;

    // loop until gap becomes 0
    for(gap = size/2; gap > 0; gap /= 2){

        // loop starting from the gap-th index and apply insertion sort logic to each gap-th elements before it.
        for(i = gap; i < size; i++){

            // hold the value of the index to sort
            int key = arr[i];

            // loop j for each gap-th element with arr[j] greater than the key value 
            // and while j is greater than gap (j lesser than gap will make j out of array bounds in the next iteration)
            for(j = i; j >= gap && key < arr[j-gap]; j -= gap){
                arr[j] = arr[j - gap];
            }

            // since j is now in the proper place in gap-th elements, place the key value in it.
            arr[j] = key;
        }

        ITERATIONS++;

    }

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int N)
{
    printf("Iterations: %d\n", ITERATIONS);
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }

}