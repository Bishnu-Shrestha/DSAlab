/*
C program to perform merge sort
*/
#include <stdio.h>
void merge_sort(int *, int, int);
void merge(int *, int, int, int);
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
    merge_sort(arr, 0, size);
}

void merge_sort(int *a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m + 1, r);
    }
}