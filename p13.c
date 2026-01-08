/*
C program to calculate a fibonacci series using recursion
*/
#include <stdio.h>
int Fibo(int);
int main(void)
{
    int n;
    printf("Enter a number to find fibonacci series to that number: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        printf("%d\t", Fibo(i));
    }
    return 0;
}

// Function to find the fibonacci number for given argument
int Fibo(int x)
{
    if (x == 1 || x == 0)
        return 1;
    else
        return (Fibo(x - 1) + Fibo(x - 2));
}