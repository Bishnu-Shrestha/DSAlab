/*
C program to perform doubly linked list operations;
*/
#include <stdio.h>
#include <stdlib.h>
// Linked list structure definition
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;
node *Head = NULL;
int tail = 0;
// Function prototypes
void Insert(int, int);
void Delete(int);
void Append(int);
void GetPos(int);
void Replace(int, int);
void Display();
void ReleaseMemory();

int main(void)
{
    int pos, val, ch = 0;
    while (ch != 7)
    {
        printf("\n*****  MENU  *****\n 1. Insert at position \n 2. Delete at position \n 3. Get index of element \n 4. Replace value at index \n 5. Append \n 6. Display \n 7. EXIT \n \t Enter your choice of operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the index and value for insertion: ");
            scanf("%d%d", &pos, &val);
            Insert(pos, val);
            break;
        case 2:
            printf("Enter the index of element to be deleted: ");
            scanf("%d", &pos);
            Delete(pos);
            break;
        case 3:
            printf("Enter the Element to be searched: ");
            scanf("%d", &val);
            GetPos(val);
            break;
        case 4:
            printf("Enter the index and value to replace the old one: ");
            scanf("%d%d", &pos, &val);
            Replace(pos, val);
            break;
        case 5:
            printf("Enter element to add to list: ");
            scanf("%d", &val);
            Append(val);
            break;
        case 6:
            Display(Head);
            break;
        case 7:
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
        printf("\nThe Doubly Linked List is empty. !!\n");
    }
    else
    {
        printf("\nDisplaying the contents of the Doubly Linked List:\n");
        node *temp = Head;
        while (temp != NULL)
        {
            printf("\t%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void Insert(int, int);
void Delete(int);
void Append(int);
void GetPos(int);
void Replace(int, int);
void ReleaseMemory();