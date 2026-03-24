/*
C program to create a stack data structure using SLL
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Stack structure (contains top pointer)
typedef struct
{
    Node *top;
} Stack;

// Push operation (insert at beginning)
void push(Stack *s, int value)
{
    // Create new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;

    printf("%d pushed to stack\n", value);
}

// Pop operation (delete from beginning)
void pop(Stack *s)
{
    if (s->top == NULL)
    {
        printf("Stack Underflow! Stack is empty\n");
    }

    Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    printf("Popped element: %d\n", value);
}

// Peek operation (view top element)
void peek(Stack *s)
{
    if (s->top == NULL)
    {
        printf("Stack is empty\n");
    }
    printf("Popped element: %d\n", s->top->data);
}

// Display stack elements
void display(Stack *s)
{
    if (s->top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    Node *current = s->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free entire stack
void freeStack(Stack *s)
{
    Node *current = s->top;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    s->top = NULL;
    printf("Stack memory freed\n");
}

int main()
{
    Stack *s;
    s->top = NULL;

    int choice, value, result;

    printf("\nSTACK IMPLEMENTATION USING SINGLY LINKED LIST\n");
    printf("MENU\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    while (1)
    {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(s, value);
            break;

        case 2:
            pop(s);

            break;

        case 3:
            peek(s);
            break;

        case 4:
            display(s);
            break;

        case 5:
            freeStack(s);
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}