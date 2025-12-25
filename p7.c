/*
A c program to perform various queue functions in a menu driven program using 
a array implementation of a linear queue.
*/

#include <stdio.h>
#define max 20
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
    q.front = 0;
    q.rear = -1;
    int ch = 1, x, d;
    printf("This is a program to perform various Queue operations:\n");
    // Menu loop for running the program until the user doesnot exit the program
    while (ch != 6)
    {
        printf("\n****MENU****\n 1. Insert\n 2. enqueue\n 3. Dequeue\n 4. Peek\n 5. Display\n 6. Exit\n");
        printf("\tEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data and position for data to be inserted: ");
            scanf("%d", &x, &d);
            break;
        case 2:
            printf("\nEnter data to Enqueue: ");
            scanf("%d", &d);
            EnQueue(&q, d);
            break;
        case 3:
            DeQueue(&q);
            break;
        case 4:
            Peek(&q);
            break;
        case 5:
            printf("\nDisplaying the contents of the Queue\n");
            Display(&q);
            break;
        case 6:
            printf("\nEXITING the program.\n");
            break;
        default:
            printf("\n!!!!ERROR!!!! please try again.\n");
            break;
        }
    } 
    return 0;
}
// Function to add element in Queue' rear
void EnQueue(queue *q1, int val)
{
    if (q1->rear == max - 1)
    {
        printf("\nThe Queue is full!!\n");
    }
    else
    {
        q1->rear++;
        q1->item[q1->rear] == val;
    }
}
//  Function to delete the front of the Queue
void DeQueue(queue *q1)
{
    if (q1->rear < q1->front)
    {
        printf("\nThe Queue is empty.\n");
    }
    else
    {
        int removed = q1->item[q1->front];
        q1->front++;
        printf("\nData %d was removed from the Queue.\n", removed);
    }
}
// Function to insert data in any position of queue
void Insert(queue *q1, int pos, int data)
{
    if (q1->rear == max - 1)
    {
        printf("\nThe Queue is full!!\n");
    }
    else if (pos < q1->front && pos > q1->rear + 1)
    {
        printf("\nInvalid position for insertion!!!!\n");
    }
    else
    {
        for (int i = q1->rear; i >= pos; i--)
        {
            q1->item[i + 1] = q1->item[i];
        }
        q1->item[pos] = data;
    }
}
// Function to display only the front of the Queue
void Peek(queue *q1)
{
    if (q1->rear < q1->front)
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
    if (q1->rear < q1->front)
    {
        printf("\nThe Queue is empty.");
    }
    else
    {
        for (int i = q1->front; i < q1->rear; i++)
        {
            printf("\t%d ", q1->item[i]);
        }
        printf("\n");
    }
}
