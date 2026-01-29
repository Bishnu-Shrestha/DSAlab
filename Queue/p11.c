/*
C program to perform priority queue using ordered array implementation
*/
#include <stdio.h>
#define max 10
// Defining my Queue structure
typedef struct QueueDf
{
    int item[max];
    int front;
    int rear;
} queue;
// Function prototypes
void DeleteLowest(queue *);
void DeleteHighest(queue *);
void Insert(queue *, int);
void Display(queue *);

int main()
{
    queue q;
    q.front = 0;
    q.rear = -1;
    int ch = 1, x, d;
    printf("This is a program to perform various Queue operations:\n");
    // Menu loop for running the program until the user doesnot exit the program
    while (ch != 5)
    {
        printf("\n****MENU****\n 1. Insert\n 2. Delete rear\n 3. Delete front\n 4. Display\n 5. Exit\n");
        printf("\tEnter your choice (1-5): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data to be Inserted: ");
            scanf("%d", &d);
            Insert(&q, d);
            break;
        case 2:
            DeleteHighest(&q);
            break;
        case 3:
            DeleteLowest(&q);
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
//  Function to delete the element at the front of the Priority Queue with ordered array implementation
void DeleteLowest(queue *q1)
{
    if (q1->rear < q1->front)
    {
        printf("\nThe Queue is empty.\n");
    }
    else
    {
        int x = q1->item[q1->front];
        for (int i = q1->front; i < q1->rear; i++)
        {
            q1->item[i] = q1->item[i + 1];
        }
        q1->rear--;
        printf("\nData %d was removed from the Queue.\n", x);
    }
}
// Function to delete the element at the end of the Priority Queue with ordered array implementation
void DeleteHighest(queue *q1)
{
    if (q1->rear < q1->front)
    {
        printf("\nThe Queue is empty.\n");
    }
    else
    {
        int x = q1->item[q1->rear];
        q1->rear--;
        printf("\nData %d was removed from the Queue.\n", x);
    }
}
/*
Function to insert elements in the queue in ascending order
*/
void Insert(queue *q1, int data)
{
    if (q1->rear == max - 1)
    {
        printf("\nThe Queue is full!! COULDN'T Insert data\n");
    }
    else
    {
        int i, j;
        for (i = q1->front; i <= q1->rear; i++)
        {
            if (data < q1->item[i])
            {
                for (j = q1->rear; j >= i; j--)
                {
                    q1->item[j + 1] = q1->item[j];
                }
                break;
            }
        }
        q1->item[i] = data;
        q1->rear++;
        printf("\nThe value %d is inserted successfully.\n", q1->item[i]);
    }
}
// Function to disp;ay all elements in the Queue
void Display(queue *q1)
{
    if (q1->rear < q1->front)
    {
        printf("\nThe Queue is empty.\n");
    }
    else
    {
        printf("\nDisplaying the contents of the Queue:\n");
        for (int i = q1->front; i <= q1->rear; i++)
        {
            printf("\t%d ", q1->item[i]);
        }
        printf("\n");
    }
}
