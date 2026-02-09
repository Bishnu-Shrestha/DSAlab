/*
C program to perform quick sort operation
*/
#include <stdio.h>
void quickSort(int *, int, int);
int partition(int *, int, int);
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
    quickSort(arr, 0, size);
    return 0;
}

void quickSort(int *a, int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}
int partition(int *a, int l, int r)
{
    int x = l, y = r, p = a[l];
    while (x < y)
    {
        while (a[x] <= p)
        {
            x++;
        }
        while (a[y] > p)
        {
            y--;
        }
        if (x < y)
        {
            int temp = a[x];
            a[x] = a[y];
            a[y] = temp;
            a[l] = a[y];
            a[y] = p;
            return y;
        }
    }
}