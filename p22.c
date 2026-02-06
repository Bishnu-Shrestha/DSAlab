// C program to perform selection sort
#include <stdio.h>
void SelectSort(int *, int);
int main()
{
    int n;
    printf("Enter the total number of elements you to sort: ");
    scanf("%d", &n);
    int data[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &data[i]);
    }
    SelectSort(data, n);
    return 0;
}
// function to perform selection sort on given data
void SelectSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = a[i];
        int minLoc = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                minLoc = j;
            }
        }
        if (i != minLoc)
        {
            a[minLoc] = a[i];
            a[i] = min;
        }
    }
    // Dusolaying the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
