#include <stdio.h>

void selectionSort(int *arr, int size);

int main(){

    int size = 10;
    int arr[] = {8, 6, 4, 9, 0, 1, 2, 6, 3, 9};

    selectionSort(arr, size);
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void selectionSort(int *arr, int size){

    int i, j, min;

    // loop until the end
    for(i = 0; i < size; i++){

        // hold the index of i
        min = i;

        // loop until the end and keep checking for an element lesser than arr[min]
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        // if there's an element lesser than min, swap them to place it in it's proper position
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }

    }


}