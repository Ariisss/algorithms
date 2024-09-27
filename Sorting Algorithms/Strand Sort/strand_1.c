#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int *elems;
    int count;
} ARRAY;

void swap(int *x, int *y);
void printArray(int arr[], int N);
int* strandSort(ARRAY *arr);
void mergeStrandOutput(int *output, int *outputSize, int *strand, int strandSize);

int main(){
    ARRAY arr;
    arr.elems = (int *)malloc(sizeof(int) * MAX);
    arr.count = 0;

    int values[] = {8, 2, 7, -5, 0, 9, 1, 2, -1, 3};

    int i;
    for (i = 0; i < MAX; i++)
    {
        arr.elems[i] = values[i];
        arr.count++;
    }

    int *output = strandSort(&arr);
    printArray(output, MAX);
}

// 1) initialize a sublist and output array with the same size as the input array
// 2) move first item of input array to sublist
// 3) traverse input array for any elements larger than the last sublist element then put it into the sublist
// 4) merge sublist to output
// 5) repeat 2 until input array is empty

int* strandSort(ARRAY *arr){

    int* sublist = (int*)malloc(sizeof(int) * arr->count);
    int* output = (int*)malloc(sizeof(int) * arr->count);
    int inputSize = arr->count;
    int outputSize = 0;

    while(arr->count > 0){
        int sublistSize = 0;
        sublist[sublistSize++] = arr->elems[0];

        int i, j = 0;
        for(i = 1; i < arr->count; i++){
            if(arr->elems[i] > sublist[sublistSize-1]){
                sublist[sublistSize++] = arr->elems[i];
            }else{
                arr->elems[j++] = arr->elems[i];
            }
        }

        arr->count = j;
        mergeStrandOutput(output, &outputSize, sublist, sublistSize);

    }

    return output;
}

void mergeStrandOutput(int *output, int *outputSize, int *strand, int strandSize){

    int mergedSize = *outputSize + strandSize;
    int *mergedArray = (int*)malloc(sizeof(int) * mergedSize);

    int x, y, z;
    x = y = z = 0;

    while(x < *outputSize && y < strandSize){
        if(output[x] <= strand[y]){
            mergedArray[z++] = output[x++];
        }else{
            mergedArray[z++] = strand[y++];
        }
    }

    while(x < *outputSize){
        mergedArray[z++] = output[x++];
    }

    while(y < strandSize){
        mergedArray[z++] = strand[y++];
    }

    for(x = 0; x < mergedSize; x++){
        output[x] = mergedArray[x];
    }

    *outputSize = mergedSize;

    free(mergedArray);
}

void swap(int *x, int *y){
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