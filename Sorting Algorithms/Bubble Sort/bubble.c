#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size);

int main(){

    int size = 10;
    int arr[] = {8, 6, 4, 9, 0, 1, 2, 6, 3, 9};

    bubbleSort(arr, size);
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void bubbleSort(int *arr, int size){

    int i, j, swapped = 1;
    // loop till the end or as long as there are swaps happening, if none, that means the array is sorted already.
    for(i = 0; i < size - 1 && swapped == 1; i++){

        // set the flag to 0
        swapped = 0;
        // for each element, loop to put larger elements at the end. For each iteration, the largest element will be correctly placed
        for(j = 0; j < size - i - 1; j++){

            // if a swap happens, trigger the flag to indicate that another loop should be done.
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
    }

}