// Lab 7
// Use recursive programming to write a menu driven program to solve problems like
// Factorial, Fibonacci sequence, GCD and Tower of Hanoi TOH problems.

#include <stdio.h>

// Function declaration's
int factorial(int n);
int fibo(int n);
int gcd(int a, int b);
void toh(char src, char aux, char dst, int n);

int main()
{
    int n, f1, ch = 1, a, b;
    long f;
    while (ch != 5)
    {
        printf("\n\n *****  MENU  ***** \n");
        printf(" 1. Factorial \n 2. Fibonacci Sequence \n 3. GCD of two numbers \n 4. TOH \n 5. Exit \n");
        printf(" Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter a number to find  its factorial: ");
            scanf("%d", &n);
            f = factorial(n);
            printf("\nFactorial of %d = %ld. ", n, f);
            break;
        case 2:
            printf("\nEnter Number of terms of the Fibonacci series to be displayed: ");
            scanf("%d", &n);
            printf("\nFibonacci Sequence upto  %d terms:\n ", n);
            for (int i = 1; i <= n; i++)
            {
                printf("%d\t", fibo(i));
            }
            break;
        case 3:
            printf("\nEnter two numbers to find their GCD: ");
            scanf("%d%d", &a, &b);
            printf("\nGCD of %d and %d = %d", a, b, gcd(a, b));
            break;
        case 4:
            printf("\nEnter number of disk: ");
            scanf("%d", &n);
            printf(" Source = A\n Destination = B\n Auxilary = C");
            toh('A', 'B', 'C', n);
            break;
        case 5:
            printf("\n ******  EXITING  ****** \n");
            break;
        default:
            printf("\nInvalid choice Please try again\n");
        }
    }
    return 0;
}
// Function to find Factorial using recursion
int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
// Function to find a member of the fibonacci series at given position
int fibo(int n)
{
    if (n == 0 || n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}
// Function to find the GCD of given numbers using recursion
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
// Function to solve the TOH problem using recursion
void toh(char src, char aux, char dst, int n)
{
    if (n == 1)
        printf("\nMove disk %d from peg %c to peg %c", n, src, dst);
    else
    {
        toh(src, dst, aux, n - 1);
        printf("\nMove disk %d from peg %c to peg %c", n, src, dst);
        toh(aux, src, dst, n - 1);
    }
}