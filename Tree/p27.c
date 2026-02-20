// Cprogram to create array implementation of tree
#include <stdio.h>
#include <math.h>
#define max 16
void Display(int *, int);
void printNode(int *, int, int);
int main()
{
    int size, arr[max], ch = 0;

    printf("Enter the size of data to sort (max=16): ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }
    Display(arr, size);
    return 0;
}

void Display(int *a, int n)
{
    int space = 5, temp = n + 1;
    printf("\t    %d\n", a[0]);
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
    if (l < n && r < n)
    {
        switch (i)
        {
        case 0:

            printf("\t/ \t\\ \n \t%d \t%d ", a[l], a[r]);
            break;
        case 1:
            printf("\t/ \t\\ \t/ \t\\ \n \t%d \t%d \t%d \t%d", a[l], a[r], a[r + 1], a[r + 2]);
            break;
    
        default:
            break;
        }
    }
    else if (l < n && r > n)
    {
        printf("\t/ \n \t%d ", a[l]);
    }
}
