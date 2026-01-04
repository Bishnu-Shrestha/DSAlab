/*
A C program to perform various queue functions in a menu driven program using
a array implementation of a circular queue.
*/
#include <stdio.h>
#define max 11 // because one spot is sacrificed in achieving the circular implementation
// Defining my Queue structure
typedef struct QueueDf
{
    int item[max];
    int front;
    int rear;
} queue;
// Function prototypes
void EnQueue(queue *, int);
void DeQueue(queue *);
void Peek(queue *);
void Insert(queue *, int, int);
void Display(queue *);

int main()
{
    queue q;
    q.front = max - 1;
    q.rear = max - 1;
    int ch = 0, x, d;
    printf("This is a program to perform various Queue operations in a Circular Queue:\n");
    // Menu loop for running the program until the user doesnot exit the program
    while (ch != 5)
    {
        printf("\n****MENU****\n 1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Display\n 5. Exit\n");
        printf("\tEnter your choice (1-5): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data to Enqueue: ");
            scanf("%d", &d);
            EnQueue(&q, d);
            break;
        case 2:
            DeQueue(&q);
            break;
        case 3:
            Peek(&q);
            break;
        case 4:
            Display(&q);
            break;
        case 5:
            printf("\n!!!! EXITING !!!! the program.\n");
            break;
        default:
            printf("\n!!!! ERROR !!!! Chosen operation is out of bound\n\tPlease try again.\n");
            break;
        }
    }
    return 0;
}
// Function to add element in rear of the Queue
void EnQueue(queue *q1, int val)
{
    if (q1->front == (q1->rear + 1) % max)
    {
        printf("\nThe Queue is full!!\n");
    }
    else
    {
        q1->item[q1->rear] = val;
        q1->rear = (q1->rear + 1) % max;
    }
}
//  Function to delete the front of the Queue
void DeQueue(queue *q1)
{
    if (q1->rear == q1->front)
    {
        printf("\nThe Queue is empty.\n");
    }
    else
    {
        int removed = q1->item[q1->front];
        q1->front = (q1->front + 1) % max;
        printf("\nData %d was removed from the Queue.\n", removed);
    }
}
// Function to display only the front element of the Queue
void Peek(queue *q1)
{
    if (q1->rear == q1->front)
    {
        printf("\nThe Queue is empty.\n");
    }
    else
    {
        printf("\nData in the front of the Queue is %d.\n", q1->item[q1->front]);
    }
}
// Function to disp;ay all elements in the Queue
void Display(queue *q1)
{
    if (q1->rear == q1->front)
    {
        printf("\nThe Queue is empty.\n");
    }
    else
    {
        printf("\nDisplaying the contents of the Queue:\n");
        for (int i = q1->front; i != q1->rear; i = (i + 1) % max)
        {
            printf("\t%d ", q1->item[i]);
        }
        printf("\n");
    }
}