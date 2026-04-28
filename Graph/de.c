#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int findMin(int dist[], int visited[], int n)
{
    int min = INF, minIndex = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < min)
            min = dist[i], minIndex = i;
    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int dist[MAX], visited[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INF, visited[i] = 0;

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++)
    {
        int u = findMin(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print results
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main()
{
    int n, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}