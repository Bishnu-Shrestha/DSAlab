/*
C program to perform merge sort
*/
#include <Stdio.h>
void InsertSort(int *, int);
int main()
{
    int n;
    printf("Enter size of data to sort: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }
    InsertSort(arr, n);
    return 0;
}

void InsertSort(int *a, int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int temp = a[i];
        for (j = i - 1; j >= 0 && temp < a[j]; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
    // Displaying the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}