#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *elems;
    int count;
} ARRAY;

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