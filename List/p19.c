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
// Function to insert given data at given position
void Insert(int pos, int val)
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
    newNode->prev = NULL;
    newNode->next = NULL;
    if (pos < 1 || pos > tail + 1)
    {
        printf("Invalid position for insertion.\n");
        free(newNode);
        return;
    }
    else if (Head == NULL)
    {
        Head = newNode;
    }
    else if (pos == 1)
    {
        newNode->next = Head;
        Head = newNode;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
    }
    printf("Inserted the value %d successfully at %d position.\n", newNode->data, pos);
    tail++;
}
// Function for adding list elements
void Append(int newVal)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Couldn't allocate memory. \n");
        return;
    }
    newNode->next = NULL;
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
    printf("Inserted %d at the end.\n", newNode->data);
}
void Delete(int pos)
{
    node *temp = Head;
    if (Head == NULL)
    {
        printf("The Doubly Linked List is empty\n");
    }
    else if (pos == 1)
    {
        Head = temp->next;
    }
    else if (pos < 1 || pos > tail)
    {
        printf("Invalid position for Deletion");
        return;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("Deleted the item %d at position %d.\n", temp->data, pos);
    }
    free(temp);
    tail--;
}
// Function to get the position of element if present in the list
void GetPos(int val)
{
    if (Head == NULL)
    {
        printf("The doubly Linked List is empty.\n");
        return;
    }
    else
    {
        node *temp = Head;
        int i = 0;
        while (temp->data != val)
        {
            if (temp->next = NULL)
            {
                printf("Element is not present in the doubly Linked List.\n");
                return;
            }
            temp = temp->next;
            i++;
        }
        printf("The value %d is located at position %d.\n", val, i);
    }
}
// Function to change the element present at given position with given value
void Replace(int pos, int val)
{
    if (Head == NULL)
    {
        printf("The doubly Linked List is empty.\n");
        return;
    }
    else
    {
        node *temp = Head;

        for (int i = 1; i < pos - 1; i++)
        {
            if (temp->next = NULL)
            {
                printf("Element is not in the doubly Linked List.\n");
                return;
            }
            temp = temp->next;
        }
        int before = temp->data;
        temp->data = val;
        printf("Replaced the value %d at position %d to %d.\n", before, pos, temp->data);
    }
}
// Function to free the memory used from the heap using malloc
void ReleaseMemory()
{
    node *temp = Head;
    while (temp != NULL)
    {
        node *new = temp->next;
        free(temp);
        temp = new;
    }
}