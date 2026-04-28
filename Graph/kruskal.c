#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int u, v, w;
} Edge;

int parent[MAX];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int x, int y)
{
    int rx = find(x), ry = find(y);
    if (rx != ry)
        parent[rx] = ry;
}

int compare(const void *a, const void *b)
{
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

void kruskal(Edge edges[], int V, int E)
{
    for (int i = 0; i < V; i++)
        parent[i] = i;

    qsort(edges, E, sizeof(Edge), compare);

    printf("MST Edges:\n");
    int total = 0, count = 0;

    for (int i = 0; i < E && count < V - 1; i++)
    {
        if (find(edges[i].u) != find(edges[i].v))
        {
            unionSet(edges[i].u, edges[i].v);
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            count++;
        }
    }

    printf("Total weight: %d\n", total);
}

int main()
{
    int V, E;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    Edge edges[MAX];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    kruskal(edges, V, E);

    return 0;
}