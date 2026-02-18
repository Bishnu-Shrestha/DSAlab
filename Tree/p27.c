// Cprogram to create array implementation of tree
#include <stdio.h>
#define max 15
void Display(int *, int);
void printNode(int *,int ,int ,int);
int main()
{
    int size, arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, ch = 0;

    // printf("Enter the size of data to sort (max=16): ");
    // scanf("%d", &size);

    // for (int i = 0; i < size; i++)
    // {
    //     printf("Enter the %d element: ", i);
    //     scanf("%d", &arr[i]);
    // }
    Display(arr, 9);
    return 0;
}

void Display(int *a, int n)
{
    int space = 5, temp = n + 1;
    for (int i = 0; i < n; i++)
    {
        printf("%*d\n", temp - 1, a[i]);
        temp--;
    }
}
