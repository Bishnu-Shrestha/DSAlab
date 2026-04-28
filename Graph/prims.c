#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int findMin(int key[], int mstSet[], int n)
{
    int min = INF, minIndex = -1;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;
    return minIndex;
}

void prim(int graph[MAX][MAX], int n)
{
    int parent[MAX], key[MAX], mstSet[MAX];

    for (int i = 0; i < n; i++)
        key[i] = INF, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int u = findMin(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                key[v] = graph[u][v], parent[v] = u;
    }

    printf("MST Edges:\n");
    int total = 0;
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total weight: %d\n", total);
}

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)

        {

            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, n);

    return 0;
}