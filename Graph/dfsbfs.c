#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty()
{
    return front == -1 || front > rear;
}

// Graph structure
int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array
int n;             // Number of vertices

// Initialize graph
void initGraph()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
}

// BFS traversal
void BFS(int start)
{
    // Reset visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty())
    {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS traversal (recursive)
void DFSRecursive(int current)
{
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < n; i++)
    {
        if (adj[current][i] == 1 && !visited[i])
            DFSRecursive(i);
    }
}

void DFS(int start)
{
    // Reset visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFSRecursive(start);
    printf("\n");
}

int main()
{
    int choice, start;

    initGraph();

    while (1)
    {
        printf("\n===== GRAPH TRAVERSAL =====\n");
        printf("1. BFS Traversal\n");
        printf("2. DFS Traversal\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter starting vertex (0 to %d): ", n - 1);
            scanf("%d", &start);
            if (start >= 0 && start < n)
                BFS(start);
            else
                printf("Invalid vertex!\n");
            break;

        case 2:
            printf("Enter starting vertex (0 to %d): ", n - 1);
            scanf("%d", &start);
            if (start >= 0 && start < n)
                DFS(start);
            else
                printf("Invalid vertex!\n");
            break;

        case 3:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}