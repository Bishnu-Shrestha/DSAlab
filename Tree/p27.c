// Cprogram to create array implementation of tree
#include <stdio.h>
#include <math.h>
#define max 15
void Display(int *, int);
void printNode(int *, int, int);
int main()
{
    int size, arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, ch = 0;

    // printf("Enter the size of data to sort (max=16): ");
    // scanf("%d", &size);

    // for (int i = 0; i < size; i++)
    // {
    //     printf("Enter the %d element: ", i);
    //     scanf("%d", &arr[i]);
    // }
    Display(arr, 10);
    return 0;
}

void Display(int *a, int n)
{
    int space = 5, temp = n + 1;
    printf("\t%d\n", a[0]);
    for (int i = 0; i < n; i++)
    {
        if (i == 1 || i == 3 || i == 7)
        {
            printf("\n");
        }
        printNode(a, i, n);
    }
}
void printNode(int *a, int i, int n)
{
    int l = 2 * i + 1, r = l + 1;
    if (l > n || r > n)
    {
        return;
    }
    printf(" \t%d \t%d ", a[l], a[r]);
}
