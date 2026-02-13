/*
program to perform heap sort
*/
#include <stdio.h>
// structure for node of the heap
typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

void heapify(Node *);
void heapsort(int *);

int main()
{
    int size;
    printf("Enter teh size of data to sort: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }
    heapsort(arr);
    // Displaying the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
void heapify(Node *);
void heapsort(int *);
