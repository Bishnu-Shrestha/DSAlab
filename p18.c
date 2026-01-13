/*
 C program to perform various singly liked list operations
 Singly Linked List: A singly linked list is a linear data structure in which each node has
 two fields:
 • One for data and another is link field.
 • The data field stores the data value and link field stores address of next node in the
  list.
 • The first node is pointed by external pointer 'start' and node at last has a NULL
pointer.
*/
#include <stdio.h>
#include <stdlib.h>
// Linked list structure definition
typedef struct node
{
    int data;
    struct node *next;
} node;
// Function prototypes
void Insert(node *, int, int);
void Delete(node *, int);
void Append(node **, int);
void Get(node *, int);
void Replace(node *, int, int);
void Display(node *);

int main(void)
{
    node *Head = NULL;
    int pos, val, ch = 0;
    while (ch != 7)
    {
        printf("\n*****  MENU  ****\n 1. Insert at position \n 2. Delete at position \n 3. Get index of element \n 4. Replace value at index \n 5. Append \n 6. Display \n 7. EXIT \n \t Enter your choice of operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the index and value for insertion: ");
            scanf("%d%d", &pos, &val);
            Insert(Head, pos, val);
            break;
        case 2:
            printf("Enter the index of element to be deleted: ");
            scanf("%d", &pos);
            Delete(Head, pos);
            break;
        case 3:
            printf("Enter the Element to be searched: ");
            scanf("%d", &val);
            Get(Head, val);
            break;
        case 4:
            printf("Enter the index and value to replace the old one: ");
            scanf("%d%d", &pos, &val);
            Replace(Head, pos, val);
            break;
        case 5:
            printf("Enter element to add to list: ");
            scanf("%d", &val);
            Append(&Head, val);
            break;
        case 6:
            Display(Head);
            break;
        case 7:
            printf("\n******  EXITING ******\n");
            break;
        default:
            printf("\n!!!!!  ERROR  !!!!! \n\tInvalid Choice please try again: \n");
            break;
        }
    }
    return 0;
}
// Function to display all the list elements
void Display(node *start)
{
    if (start == NULL)
    {
        printf("\nThe Linked List is empty. !!\n");
    }
    else
    {
        printf("\nDisplaying the contents of the Linked List:\n");
        node *temp = start;
        while (temp != NULL)
        {
            printf("\t%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
// Function for adding list elements
void Append(node **start, int newVal)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Couldn't allocate memory. ");
        return;
    }
    newNode->data = newVal;
    if (*start == NULL)
    {
        (*start)->next = newNode;
    }
    else
    {
        node **temp = start;
        while ((*temp)->next != NULL)
        {
            *temp = (*temp)->next;
        }
        (*temp)->next = newNode;
    }
    newNode->next = NULL;
}
void Insert(node *start, int pos, int val) {}
void Delete(node *start, int pos) {}
void Get(node *start, int val) {}
void Replace(node *start, int pos, int val) {}