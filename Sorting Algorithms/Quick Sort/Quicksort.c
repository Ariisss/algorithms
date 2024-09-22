#include <stdio.h>
#include <stdlib.h>
#define none -1

int ITERATIONS = 0;
int SWAPS = 0;
int RECURSIONS = 0;

void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
int lomutoPartition( int *arr, int low, int high);
int hoarePartition(int *arr, int low, int high);
int hoarePartition2(int *arr, int low, int high);
void hoareQuicksort(int *arr, int low, int high);
// void medianOfThree(int *arr, int low, int high);
void medianOfThree(int *x, int *y, int *z);
void swap(int *x, int *y);



int main(){
    //TEST CASES

    //normal array
    // printf("Normal Array\n");
    // int arr[] = {3, 6, 8, 10, 1, 2, 1};
    // int arr[] = {
    //     23, 5, 89, 12, 55, 78, 34, 90, 67, 14,
    //     42, 33, 18, 81, 61, 9, 97, 24, 70, 11,
    //     4, 65, 86, 15, 39, 50, 88, 27, 2, 72,
    //     48, 99, 31, 3, 75, 58, 28, 20, 44, 82,
    //     56, 93, 17, 6, 76, 41, 22, 95, 1, 62
    // };
    // int arr[] = {2, 9, 3, 5, 1, 7, 0 ,6 ,8 ,4};
    // int n = sizeof(arr) / sizeof(arr[0]);

    //sorted array
    // printf("Sorted Array\n");
    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // reverse sorted array
    // printf("Reverse Sorted Array\n");
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    //identical array
    // printf("Identical Array\n");
    // int arr[] = {5, 5, 5, 5, 5, 5, 5};
    // int n = sizeof(arr) / sizeof(arr[0]);

    //single element array
    // printf("Single Element Array\n");s
    // int arr[] = {42};
    // int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    // printf("LOMUTO VERSION\n");
    // quicksort(arr, 0, n-1);

    printf("\nHOARE VERSION\n");
    hoareQuicksort(arr, 0, n-1);


    printf("\nAfter Sorting: ");

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
        if(i > 0 && (i % 12 == 0)){
            printf("\n");
        }
    }

    printf("\nRECURSIONS: %d", RECURSIONS);
    printf("\nSWAPS: %d", SWAPS);

    return 0;
}

void quicksort(int *arr, int low, int high)
{
    if(low < high)
    {
        int pivotIndex = lomutoPartition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex+1, high);
        RECURSIONS++;
    }
}

void hoareQuicksort(int *arr, int low, int high){

    if(low < high){
        int pivotIndex = hoarePartition2(arr, low, high);
        hoareQuicksort(arr, low, pivotIndex);
        hoareQuicksort(arr, pivotIndex + 1, high);
        RECURSIONS++;
    }

}

int hoarePartition2(int *arr, int low, int high){
	int x, y, mid, pivot;
    
    mid = (low+high)/2;
    medianOfThree(&arr[low],&arr[mid],&arr[high]);
    pivot = arr[high];
 
    x = low;
    y = high;
    while (x < y) {
        for(; x < y && arr[x] < pivot; x++) {}
        for(; y > x && arr[y] >= pivot; y--) {}
        if(x < y){
        	int temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
            SWAPS++;
		}
    };
 
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    return x;
}

void medianOfThree(int *x, int *y, int *z){ //we want smallest, largest, middle
    if (*x <= *y && *y <= *z){
        swap(y,z); 
    } else if (*x <= *z && *z <= *y) {
    	//do nothing
	} else if (*y <= *x && *x <= *z) {
		swap(x,y); 
		swap(y,z); 
	} else if (*y <= *z && *z <= *x) {
		swap(x,y); 
	} else if (*z <= *x && *x <= *y) {
		swap(x,z);
	} else {
		swap(y,z); 
		swap(x,y); 
	}
    
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
	SWAPS++;
}

int hoarePartition(int *arr, int low, int high){

    int pivot = arr[low];
    int x = low - 1, y = high + 1;
    // int x = low, y = high;

    while(1){
        do{
            x++;
            ITERATIONS++;
        }while(arr[x] < pivot);

        do{
            y--;
            ITERATIONS++;
        }while(arr[y] > pivot);

        if(x >= y){
            return y; 
        }

        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
        SWAPS++;
    }

}

int lomutoPartition(int *arr, int low, int high){

    int pivot = arr[high];
    int i = low, j;

    for(j = low; j < high; j++){

        if(arr[j] < pivot){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            SWAPS++;
        }

        ITERATIONS++;

    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    SWAPS++;

    return i;

}

int partition(int *arr, int low, int high){
    
    int x = low, y = high;
    int pivot = arr[low];

    while(x < y){
        for( ; x < y && arr[x] <= pivot; x++){ITERATIONS++;};
        for( ; y >= x && arr[y] > pivot ; y--){ITERATIONS++;};
        if(x < y){
            int temp;
            temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
            SWAPS++;
        }
    }

    int temp;
    temp = arr[y];
    arr[y] = arr[low];
    arr[low] = temp;
    SWAPS++;

    return y;
}

