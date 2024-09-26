#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *elems;
    int count;
} ARRAY;

void swap(int *x, int *y);
void printArray(int arr[], int N);
void strandSort(ARRAY *arr);

int main(){

}

// 1) initialize a sublist and output array with the same size as the input array
// 2) move first item of input array to sublist
// 3) traverse input array for any elements larger than the last sublist element then put it into the sublist
// 4) merge sublist to output
// 5) repeat 2 until input array is empty

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