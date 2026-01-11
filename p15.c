/*
C program to find GCD of given number using recursion
*/
#include <stdio.h>
int FindGCD(int, int);
int main(void)
{
    int x, y, z;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d%d", &x, &y);
    z = FindGCD(x, y);
    printf("The GCD for %d and %d is %d.\n", x, y, z);
    return 0;
}
// Function to find GCD recursively
int FindGCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return FindGCD(b, a % b);
}