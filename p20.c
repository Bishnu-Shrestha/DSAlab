/*
C program to perform various circular linked list functions
*/
#include <stdio.h>
#include <stdlib.h>
// Defining the structure for a node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
// initializing the head and tail pointer for the circular linked list to NULL
Node *Head = NULL;
Node *Tail = NULL;
// function prototypes
void InsertBegining(int);
void InsertEnd(int);
void DeleteBegining();
void DeleteEnd();
void Display();
void ReleaseMemory();
int main(void)
{
    int ch = 0, val = 0;
    while (ch != 6)
    {
        printf("******  MENU  ******\n 1. Insert at begining \n 2. Insert at end \n 3. Delete at begining \n 4. Delete at End \n 5. EXIT \n \t Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a value to be inserted at the begining of the CLL: ");
            scanf("%d", &val);
            InsertBegining(val);
            break;
        case 2:
            printf("Enter a value to be inserted at the End of the CLL: ");
            scanf("%d", &val);
            InsertEnd(val);
            break;
        case 3:
            DeleteBegining();
            break;
        case 4:
            DeleteEnd();
            break;
        case 5:
            Display();
            break;
        case 6:
            printf("\n******  EXITING  ******\n");
            ReleaseMemory();
            break;
        default:
            printf("\n!!!!!  ERROR  !!!!! \n\tInvalid Choice please try again: \n");
            break;
        }
    }

    return 0;
}
