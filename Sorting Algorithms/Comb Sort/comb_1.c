#include <stdio.h>

void printArray(int arr[], int N);
void swap(int *a, int *b);
void combSort(int *arr, int size);

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 5, 15 , 1, 0 };
    int N = sizeof(arr) / sizeof(arr[0]);

    combSort(arr, N);
    printArray(arr, N);


    return 0;
}

void combSort(int *arr, int size){

    int gap, i;
    int swapped = 1;

    // loop until gap is not one OR if the swap flag is true to check for misplaced elements in the array
    while(gap != 1 || swapped == 1){

        // shrink gap by 1.3
        gap /= 1.3;

        //if gap is less than one, we turn gap to 1 to account for checking loops (when swapped = 1 and gap is already 1)
        if(gap < 1){
            gap = 1;
        }
        swapped = 0;

        // this is basically bubble sort but comparing elements with a gap interval
        for(i = 0; (i + gap) < size; i++){
            if(arr[i] > arr[i + gap]){
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
            }
        }
    }

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