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
node *Head = NULL;
int tail = 0;
// Function prototypes
void Insert(int, int);
void Delete(int);
void Append(int);
void GetPos(int);
void Replace(int, int);
void Display();

int main(void)
{
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
void Display()
{
    if (Head == NULL)
    {
        printf("\nThe Linked List is empty. !!\n");
    }
    else
    {
        printf("\nDisplaying the contents of the Linked List:\n");
        node *temp = Head;
        while (temp != NULL)
        {
            printf("\t%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
// Function for adding list elements
void Append(int newVal)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Couldn't allocate memory. ");
        return;
    }
    newNode->next = NULL;
    newNode->data = newVal;
    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        node *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    tail++;
}
// Function to insert given data at given position
void Insert(int pos, int val)
{
    if (pos < 1 || pos > tail + 1)
    {
        printf("Invalid position for insertion");
        return;
    }
    else
    {
        node *newNode, *temp;
        temp = Head;
        newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("Couldn't allocate memory. ");
            return;
        }
        newNode->data = val;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted the value %d successfully.\n", newNode->data);
    }
}
// Function to delete the indexed element.
void Delete(int pos)
{
    if (Head == NULL)
    {
        printf("The Linked List is empty.\n");
        return;
    }
    else if (pos < 1 || pos > tail + 1)
    {
        printf("Invalid position for Deletion");
        return;
    }
    else
    {
        node *temp;
        temp = Head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("Couldn't Deleter the given position.\n");
                return;
            }
        }
        node *hold;
        hold = temp->next;
        temp->next = hold->next;
        printf("Deleted the %d item %d.\n", pos, hold->data);
        free(hold);
    }
}
void GetPos(int val) {}
void Replace(int pos, int val) {}