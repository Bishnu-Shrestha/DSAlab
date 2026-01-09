/*
program to find sum of natural numbers using recursion
*/
#include <stdio.h>
int Sum(int);
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum to %d is %d.\n", n, Sum(n));
    return 0;
}
// Function to calculate sum to given number
int Sum(int a)
{
    if (a == 1)
        return 1;
    else
        return a + Sum(a - 1);
}