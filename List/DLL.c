#include <stdio.h>
#include <stdlib.h>

// Node structure with prev and next pointers
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Doubly linked list structure
typedef struct
{
    Node *head;
    Node *tail;
} DoublyList;

// Initialize doubly linked list
void initList(DoublyList *list)
{
    list->head = NULL;
    list->tail = NULL;
}
// Insert at beginning
void insertAtBeginning(DoublyList *list, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head == NULL)
    {
        list->tail = newNode;
    }
    else
    {
        list->head->prev = newNode;
    }
    list->head = newNode;
    printf("%d inserted at beginning\n", value);
}

// Insert at end
void insertAtEnd(DoublyList *list, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        list->tail->next = newNode;
    }

    list->tail = newNode;
    printf("%d inserted at end\n", value);
}

// Delete from beginning
void deleteFromBeginning(DoublyList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty! Cannot delete\n");
        return;
    }

    Node *temp = list->head;
    int value = temp->data;

    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
        list->head->prev = NULL;
    }

    free(temp);
    printf("Deleted from beginning\n");
    printf("Deleted element: %d\n", value);
}

// Delete from end
void deleteFromEnd(DoublyList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty! Cannot delete\n");
        return;
    }

    Node *temp = list->tail;
    int value = temp->data;

    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }

    free(temp);
    printf("Deleted from end\n");
    printf("Deleted element: %d\n", value);
}

// Display forward traversal
void display(DoublyList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List elements: ");
    Node *current = list->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free entire list
void freeList(DoublyList *list)
{
    Node *current = list->head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

int main()
{
    DoublyList list;
    initList(&list);

    int choice, value, result;

    printf("\nDOUBLY LINKED LIST IMPLEMENTATION\n");
    printf("\tMENU\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Delete from beginning\n");
    printf("4. Delete from end\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtBeginning(&list, value);
            break;

        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(&list, value);
            break;

        case 3:
            deleteFromBeginning(&list);
            break;

        case 4:
            deleteFromEnd(&list);
            break;

        case 5:
            display(&list);
            break;

        case 6:
            freeList(&list);
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}