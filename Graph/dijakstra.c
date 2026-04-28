#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices

// Function to find the vertex with minimum distance
int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's algorithm function
void dijkstra(int graph[V][V], int src)
{
    int dist[V];    // Output array (shortest distances)
    int visited[V]; // Visited set

    // Initialize distances and visited array
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Main function
int main()
{
    int source, n = 5;
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}};
    printf("The vertices in the graph are 0, 1, 2, 3, 4.\n");
    printf("The adjacency matrix is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%-6d", graph[i][j]);
        }
        printf("\n");
    }

    printf("Enter a source vertex: ");
    scanf("%d", &source);
    dijkstra(graph, source); // Source node = 0
    return 0;
}