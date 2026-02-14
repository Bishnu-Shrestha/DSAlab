/*
program to perform heap sort
*/
#include <stdio.h>
#include <math.h>
#define max 16
void buildHeap(int *, int);
void heapify(int *, int);
void heapsort(int *);

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
    heapify(arr, size);
    // Displaying the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
void buildHeap(int *a, int s)
{
    for (int i = s / 2 - 1; i >= 0; i--)
    {
        heapify(a, i);
    }
}
void heapify(int *a, int s)
{
    for (int i = 0; i < s; i++)
    {

        int l = 2 * i + 1, r = 2 * i + 2, temp;

        if (l > s || r > s)
        {
            break;
        }
        else if (a[i] < a[l] && a[l] > a[r])
        {
            temp = a[i];
            a[i] = a[l];
            a[l] = temp;
        }
        else if (a[i] < a[r] && a[r] > a[l])
        {
            temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
}
void heapsort(int *);
