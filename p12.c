/*
C program to find the factorial of given number using recursion
*/
#include <stdio.h>

int Facto(int);
int main(void)
{
    int n;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);
    printf("\nThe factorial of %d is %d.\n", n, Facto(n));
    return 0;
}
// Function for calculating a factorial for given number
int Facto(int a)
{
    // Base case
    if (a == 1 || a == 0)
    {
        return 1;
    }
    // 4!=4*3!...4!=4*3*2*1!
    else
    {
        return (a * Facto(a - 1));
    }
}