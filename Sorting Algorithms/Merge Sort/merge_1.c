#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *elems;
    int count;
} ARRAY;

// 1) initialize leftNdx (leftmost index) and rightNdx (MAX-1)
// 2) if leftNdx < rightNdx, we get the middle index with formula [leftNdx + (rightNdx - 1) / 2]
// 3) divide/make 2 sub arrays, left size is leftNdx to middle, right size is middle + 1 to rightNdx
// 4) repeat 1 until each sub array only has 1 element
// 5) 


void swap(int *x, int *y);
void printArray(int arr[], int N);

int main(){

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