/*
C program to perform merge sort
*/
#include <stdio.h>
void merge_sort(int *, int);
void merge(int *, int *, int *, int);
int main()
{
    int size;
    printf("Enter the size of data to sort: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, size);
    // Displaying the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
// Function to divide the array into halves
void merge_sort(int *a, int r)
{
    if (r <= 1) // base case
        return;
    // size for the left and right portion of the array
    int m = r / 2, n = r - m;
    int leftArr[m], rightArr[r - m];
    int i = 0, j = 0; // index trackers
    for (; i < r; i++)
    {
        if (i < m)
            leftArr[i] = a[i];
        else
        {
            rightArr[j] = a[i];
            j++;
        }
    }
    merge_sort(leftArr, m);
    merge_sort(rightArr, n);
    merge(leftArr, rightArr, a, r);
}
// Function to merge the left half and the right half of the initial array
void merge(int *lAr, int *rAr, int *arr, int size)
{

    int leftSiz = size / 2, rightSiz = size - leftSiz;
    int i = 0, l = 0, r = 0;
    while (l < leftSiz && r < rightSiz)
    {
        if (lAr[l] < rAr[r])
        {
            arr[i] = lAr[l];
            l++;
        }
        else
        {
            arr[i] = rAr[r];
            r++;
        }
        i++;
    }
    while (l < leftSiz)
    {
        arr[i] = lAr[l];
        i++;
        l++;
    }
    while (r < rightSiz)
    {
        arr[i] = rAr[r];
        i++;
        r++;
    }
}