/*
Queue data structure implementation using SLL 
*/
#include <stdio.h>
#include <stdlib.h>
// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Queue structure with front and rear pointers
typedef struct
{
    Node *front;
    Node *rear;
} Queue;

// Enqueue operation (insert at rear)
void enqueue(Queue *q, int value)
{
    // Create new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, both front and rear point to new node
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        // Add new node at rear and update rear
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("%d enqueued to queue\n", value);
}

// Dequeue operation (delete from front)
void dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }

    Node *temp = q->front;
    int value = temp->data;

    // Move front to next node
    q->front = q->front->next;

    // If queue becomes empty, rear also becomes NULL
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    printf("Dequeued element: %d\n", value);
}

// Get front element without deleting
void front(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", q->front->data);
}
// Display queue elements
void display(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements (front to rear): ");
    Node *current = q->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
// Free entire queue
void freeQueue(Queue *q)
{
    Node *current = q->front;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    q->front = NULL;
    q->rear = NULL;
    printf("Queue memory freed\n");
}

int main()
{
    Queue *q;
    // initializing the queue
    q->front = NULL;
    q->rear = NULL;

    int choice, value, result;

    printf("\nQUEUE IMPLEMENTATION USING SINGLY LINKED LIST\n");
    printf("\tMENU\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
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
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(q, value);
            break;

        case 2:
            dequeue(q);

            break;

        case 3:
            front(q);

            break;
        case 4:
            display(q);
            break;
        case 5:
            freeQueue(q);
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}