#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int SWAPS = 0;
int ITERATIONS = 0;
int SHIFTS = 0;

typedef struct
{
    char name[20];
    int age;
} DATA;

typedef struct
{
    int id;
    DATA stud;
} CELL;

typedef struct list
{
    CELL cell;
    struct list *link;
} *LIST, NODE;

// 1) Selection Sort
void selectionSort(LIST *L);
// 2) Bubble Sort
void bubbleSort(LIST *L);
// 3) Insertion Sort
void insertionSort(LIST *L);

// Util Functions
void printArray(int arr[], int size);
void printList(LIST list);
void populateList(LIST *list, CELL arr[]);

int main()
{

    CELL data[] = {
        {101, {"Alice", 23}},
        {105, {"Bob", 19}},
        {102, {"Charlie", 21}},
        {110, {"Daisy", 22}},
        {104, {"Eve", 20}},
        {107, {"Frank", 25}},
        {103, {"Grace", 18}},
        {109, {"Henry", 24}},
        {106, {"Ivy", 21}},
        {108, {"Jack", 19}}
    };

    LIST list = NULL;

    populateList(&list, data);
    // bubbleSort(&list);
    selectionSort(&list);
    printList(list);

}

void selectionSort(LIST *L){

    int swapped = 1;
    LIST *trav = L;

    while(swapped || *trav != NULL){

        LIST *trav2;
        swapped = 0;
        // CELL min = (*trav)->cell;
        LIST *min = trav;

        for( trav2 = trav; *trav2 != NULL; trav2 = &(*trav2)->link ){
            if((*min)->cell.stud.age > (*trav2)->cell.stud.age){
                min = trav2;
                swapped = 1;
            }
        }

        if(min != trav){
            CELL temp = (*min)->cell;
            (*min)->cell = (*trav)->cell;
            (*trav)->cell = temp;
        }

        trav = &(*trav)->link;

    }
}

void bubbleSort(LIST *L)
{

    int swapped = 1;
    LIST *trav = L;

    while (swapped == 1)
    {
        swapped = 0;
        for (trav = L; (*trav)->link != NULL; trav = &(*trav)->link)
        {
            if ((*trav)->cell.stud.age > (*trav)->link->cell.stud.age)
            {
                CELL temp = (*trav)->cell;
                (*trav)->cell = (*trav)->link->cell;
                (*trav)->link->cell = temp;
                swapped = 1;
            }
        }
    }
}


void populateList(LIST *list, CELL arr[])
{

    LIST *trav = list;
    int i;

    for (i = 0; i < MAX; i++)
    {

        LIST temp = malloc(sizeof(NODE));
        if (temp != NULL)
        {
            temp->cell = arr[i];
            temp->link = NULL;
        }

        *trav = temp;
        trav = &(*trav)->link;
    }
}

void printList(LIST list)
{

    for (; list != NULL; list = list->link)
    {
        printf("ID: %-5d | Name: %-15s | Age: %-4d\n", list->cell.id, list->cell.stud.name, list->cell.stud.age);
    }
}

void printArray(int arr[], int N)
{

    printf("# of Iterations: %d\n", ITERATIONS);
    printf("# of Swaps: %d\n", SWAPS);
    printf("# of Shifts: %d\n", SHIFTS);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}