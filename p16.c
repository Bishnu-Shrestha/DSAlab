/*
C program to solve the Tower Of Hanoi problem using Recursion
*/
#include <stdio.h>
int count = 0;
void TOH_alg(int, char, char, char);
int main(void)
{
    int num;
    printf("Enter the number of the disks in the source peg: ");
    scanf("%d", &num);
    TOH_alg(num, 'A', 'B', 'C');
    printf("\nIteration's %d\n", count);
    return 0;
}
// Function to state the steps for moving the discs to solve the problem.
void TOH_alg(int n, char Source, char Destination, char Auxilary)
{
    if (n == 1)
        printf("Move from %c to %c.\n", Source, Destination);
    else
    {
        TOH_alg(n - 1, Source, Auxilary, Destination);
        printf("Move from %c to %c.\n", Source, Destination);
        TOH_alg(n - 1, Auxilary, Destination, Source);
    }
    count++;
}