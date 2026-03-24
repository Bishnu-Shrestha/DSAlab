// C program to perform bobble sort
#include <stdio.h>
void BobbleSort(int *, int);
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
    BobbleSort(data, n);
    printf("\nAfter sorting: ");
    display(data, n);
    return 0;
}
// Function to bobble sort the array in place and display it
void BobbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
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