/*
program for heap data structure implementation
*/
#include <stdio.h>
#define max 10
void Insert(int *, int);
void Delete(int *, int);
void Display(int *, int);
void Heapify(int *, int, int);
int main()
{
    int arr[max], size, ch;
    printf("Enter the size of heap(<=%d): ", max);
    scanf("%d", &size);
    while (ch != 5)
    {
        printf("\n****** MENU ******\n1. Insert\n2. Delete\n3. Display\n4. Heapify\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Insert(arr, size);
            break;
        case 2:
            Delete(arr, size);
            break;
        case 3:
            Display(arr, size);
            break;
        case 4:
            Heapify(arr, size, 0);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\nTry again.\n");
        }
    }
    return 0;
}
// Function to insert an element into the heap
void Insert(int *a, int n)
{
    if (n >= max)
    {
        printf("Heap is full. Cannot insert new element.\n");
        return;
    }
    int key;
    printf("Enter the element to insert: ");
    scanf("%d", &key);
    a[n] = key;
    Heapify(a, n, 0);
}
// Function to delete an element from the heap
void Delete(int *a, int n)
{
    if (n <= 0)
    {
        printf("Heap is empty. Cannot delete element.\n");
        return;
    }
    int key;
    printf("Enter the element to delete: ");
    scanf("%d", &key);
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            break;
    }
    if (i == n)
    {
        printf("Element not found in heap.\n");
        return;
    }
    a[i] = a[n - 1];
    Heapify(a, n - 1, i);
}
// Function to display the elements of the heap
void Display(int *a, int n)
{
    if (n <= 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// Function to maintain the heap property
void Heapify(int *a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        Heapify(a, n, largest);
    }
}