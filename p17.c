/*
 C program to perform list operations in a menu driven way
  A List ADT is an abstract data type that defines a collection of elements
    arranged in a linear order, along with the operations that can be performed on
    them, independent of how the list is implemented.
 Basic Operations of List ADT
 • create() – create an empty list
 • isEmpty() – check whether the list is empty
 • size() – return number of elements
 • insert(i, x) – insert element x at position i
 • delete(i) – remove element from position i
 • get(i) – access element at position i
 • set(i, x) – update element at position i
 • traverse() – visit all elements in order
*/
#include <stdio.h>
#define max 6
// my list structure
typedef struct
{
    int data[max];
    int rear;
} list;
// Function prototypes
int isEmpty(list *);
int isFull(list *);
void Append(list *, int);
void Insert(list *, int, int);
void Delete(list *, int);
void Get(list *, int);
void Set(list *, int, int);
void Display(list *);
int main()
{
    list L1;
    L1.rear = -1;
    int ch = 0, pos, val;
    while (ch != 7)
    {
        printf("\n*****  MENU  ****\n 1. Insert \n 2. Delete \n 3. Get index of element \n 4. Replace value at index \n 5. Append \n 6. Display \n 7. EXIT \n \t Enter your choice of operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the index and value for insertion: ");
            scanf("%d%d", &pos, &val);
            Insert(&L1, pos, val);
            break;
        case 2:
            printf("Enter the index of element to be deleted: ");
            scanf("%d", &pos);
            Delete(&L1, pos);
            break;
        case 3:
            printf("Enter the Element to be searched: ");
            scanf("%d", &val);
            Get(&L1, val);
            break;
        case 4:
            printf("Enter the index and value to replace the old one: ");
            scanf("%d%d", &pos, &val);
            Set(&L1, pos, val);
            break;
        case 5:
            printf("Enter element to add to list: ");
            scanf("%d", &val);
            Append(&L1, val);
            break;
        case 6:
            Display(&L1);
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
// Function to check for full state of the list
int isFull(list *a)
{
    if (a->rear == max - 1)
        return 1;
    else
        return 0;
}
// Function to check for empty state of the list
int isEmpty(list *a)
{
    if (a->rear == -1)
        return 1;
    else
        return 0;
}
// function to add value to the end of the list
void Append(list *l, int data)
{
    if (!isFull(l))
    {
        l->rear++;
        l->data[l->rear] = data;
        printf("Added %d to the list successfully.\n", l->data[l->rear]);
    }
    else
        printf("Couldn't append!!, The list is full.\n");
}
// Function to insert given data at given position (index)
void Insert(list *q1, int pos, int data)
{
    if (isFull(q1))
    {
        printf("\nCouldn't insert. The List is full.!!\n");
    }
    else if (pos < 0 || pos > q1->rear + 1)
    {
        printf("\nInvalid position for insertion. !!!!\n");
    }
    else
    {
        for (int i = q1->rear; i >= pos; i--)
        {
            q1->data[i + 1] = q1->data[i];
        }
        q1->rear++;
        q1->data[pos] = data;
        printf("\nThe value %d has been inserted successfully.\n", q1->data[pos]);
    }
}
// Function for Deleting the value at given index
void Delete(list *q1, int pos)
{
    if (isEmpty(q1))
    {
        printf("\nCouldn't Delete. The List is Empty.!!\n");
    }
    else if (pos < 0 || pos > q1->rear + 1)
    {
        printf("\nInvalid position for Deletion. !!!!\n");
    }
    else
    {
        int temp = q1->data[pos];
        for (int i = pos; i < q1->rear; i++)
        {
            q1->data[i] = q1->data[i + 1];
        }
        q1->rear--;
        printf("The value %d has been deleted from the List successfully.\n", temp);
    }
}
// Function to find index of element in the list
void Get(list *a, int data)
{
    if (!isEmpty(a))
    {
        for (int i = 0; i <= a->rear; i++)
        {
            if (a->data[i] == data)
            {
                printf("\nThe value %d is located at index %d in the List.\n", data, i);
                return;
            }
        }
        printf("!!!!!! Element not Found. !!!!!!\n");
    }
    else
        printf("Couldn't Get index. The List is empty.!!\n");
}
// Function to replace the value at given index
void Set(list *q1, int pos, int data)
{
    if (pos < 0 || pos > q1->rear)
    {
        printf("\nInvalid position for Replacing value of list. !!!!\n");
    }
    else
    {
        int temp = q1->data[pos];
        q1->data[pos] = data;
        printf("\nThe value %d has been replaced by %d successfully.\n", temp, q1->data[pos]);
    }
}
// Function to display all the list elements
void Display(list *q1)
{
    if (isEmpty(q1))
    {
        printf("\nThe List is empty. !!\n");
    }
    else
    {
        printf("\nDisplaying the contents of the List:\n");
        for (int i = 0; i <= q1->rear; i++)
        {
            printf("\t%d ", q1->data[i]);
        }
        printf("\n");
    }
}
