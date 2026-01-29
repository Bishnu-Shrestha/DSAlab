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
} node;
// initializing the head and tail pointer for the circular linked list to NULL
node *Head = NULL;
node *Tail = NULL;
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
        printf("\n******  MENU  ******\n 1. Insert at begining \n 2. Insert at end \n 3. Delete at begining \n 4. Delete at End \n 5. Display \n 6. EXIT \n \t Enter your choice: ");
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
// Function to display all the list elements
void Display()
{
    if (Head == NULL)
    {
        printf("\nThe Singly Linked List is empty. !!\n");
    }
    else
    {
        printf("\n Displaying the contents of the Circular Linked List:\n");
        node *temp = Head;

        do
        {
            printf("\t%d ", temp->data);
            temp = temp->next;
        } while (temp != Head);
        printf("\n");
    }
}
// Function to insert given data at given position
void InsertBegining(int val)
{
    node *newNode, *temp;
    temp = Head;
    newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Couldn't allocate memory.\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    if (Head == NULL)
    {
        Head = newNode;
        newNode->next = Head;
        Tail = Head;
    }
    else
    {
        newNode->next = Head;
        Head = newNode;
        Tail->next = Head;
    }

    printf("Inserted the value %d successfully. \n", newNode->data);
}

void InsertEnd(int val) {}
void DeleteBegining() {}
void DeleteEnd() {}
void ReleaseMemory() {}