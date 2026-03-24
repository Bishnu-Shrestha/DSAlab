// C program to perform selection sort
#include <stdio.h>
void SelectSort(int *, int);
void display(int *a, int n);
int main()
{
    int n;
    printf("Enter the total number of elements you want to sort: ");
    scanf("%d", &n);
    int data[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &data[i]);
    }
    printf("\nBefore sorting: ");
    display(data, n);
    SelectSort(data, n);
    printf("\nAfter sorting: ");
    display(data, n);
    return 0;
}
// function to perform selection sort on given data
void SelectSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (i != min)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
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