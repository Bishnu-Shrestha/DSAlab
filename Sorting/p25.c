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
    // Displaying the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
/*
Recursive function for finding the pivot and calling the
quick sort function accordingly for left and right half
*/
void quickSort(int *a, int l, int r)
{
    if (r <= l)
        return;

    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}
// Function to make partition of the array i.e divide step
int partition(int *a, int l, int r)
{
    int p = a[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (a[j] < p)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    i++;
    int temp = a[i];
    a[i] = a[r];
    a[r] = temp;
    return i;
}