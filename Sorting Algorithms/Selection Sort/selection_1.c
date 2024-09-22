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

    for(i = 0; i < size; i++){

        min = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }

    }


}