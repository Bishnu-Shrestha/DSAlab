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
