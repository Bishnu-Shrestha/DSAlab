/*
C program to perform insertion sort
*/
#include <Stdio.h>
void InsertSort(int *, int);
void display(int *a, int n);
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
    printf("\nBefore sorting: ");
    display(arr, n);
    InsertSort(arr, n);
    printf("\nAfter sorting: ");
    display(arr, n);
    return 0;
}
// Function to perform insertion sort
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
}
// display function
void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}