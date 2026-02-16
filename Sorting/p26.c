/*
program to perform heap sort
*/
#include <stdio.h>
#include <math.h>
#define max 16
void buildHeap(int *, int);
void heapify(int *, int, int);
void heapsort(int *, int);

int main()
{
    int size, arr[max];
    printf("Enter the size of data to sort (max=16): ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }
    // converting the given input into max heap
    buildHeap(arr, size);
    // sorting the max heap using heap sort
    heapsort(arr, size);
    // Displaying the sorted array
    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
// Function to create max heap recursively
void buildHeap(int *a, int s)
{
    for (int i = (s / 2) - 1; i >= 0; i--)
    {
        heapify(a, i, s);
    }
}
// Function to create heap of each node
void heapify(int *a, int i, int s)
{
    int largest = i, left = (2 * i) + 1, right = (2 * i) + 2;
    if (left < s && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < s && a[right] > a[largest])
    {
        largest = right;
    }
    // if largest is not root
    if (largest != i)
    {
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        heapify(a, largest, s);
    }
}
// Function to sort the elements in a heap
void heapsort(int *a, int s)
{
    int last = s - 1;
    // swap the first and last elements;
    int temp = a[0];
    a[0] = a[last];
    a[last] = temp;
    // check for the presence of element to convert to heap and stop the recursion
    if (s < 2)
    {
        return;
    }
    else
    {
        buildHeap(a, last);
        heapsort(a, last);
    }
}
