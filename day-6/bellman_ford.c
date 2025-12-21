#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge
{
    int u, v;
    int w;
};

int main(void)
{
    int V, E;
    printf("Enter number of vertices and edges (V E): ");
    if (scanf("%d %d", &V, &E) != 2 || V <= 0 || E < 0)
    {
        fprintf(stderr, "Invalid V or E\n");
        return 1;
    }

    printf("\n--- Graph Info ---\n");
    printf("Vertices: %d\n", V);
    printf("Edges: %d\n\n", E);

    struct Edge *edges = malloc(sizeof(struct Edge) * E);
    if (!edges)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d edges in format: u v w\n", E);
    printf("(Example: 0 1 -3 means edge from 0 to 1 weight -3)\n\n");

    for (int i = 0; i < E; ++i)
    {
        printf("Edge %d: ", i);
        if (scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w) != 3)
        {
            fprintf(stderr, "Invalid edge input\n");
            free(edges);
            return 1;
        }
        if (edges[i].u < 0 || edges[i].u >= V || edges[i].v < 0 || edges[i].v >= V)
        {
            fprintf(stderr, "Edge %d has invalid vertex index\n", i);
            free(edges);
            return 1;
        }
    }

    int src;
    printf("\nEnter source vertex (0 to %d): ", V - 1);
    if (scanf("%d", &src) != 1 || src < 0 || src >= V)
    {
        fprintf(stderr, "Invalid source vertex\n");
        free(edges);
        return 1;
    }

    long long *dist = malloc(sizeof(long long) * V);
    if (!dist)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(edges);
        return 1;
    }

    for (int i = 0; i < V; ++i)
        dist[i] = LLONG_MAX;
    dist[src] = 0LL;

    printf("\nRunning Bellman-Ford...\n\n");

    for (int i = 0; i < V - 1; ++i)
    {
        printf("Iteration %d:\n", i + 1);

        int changed = 0;
        for (int j = 0; j < E; ++j)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] == LLONG_MAX)
                continue;

            long long cand = dist[u] + (long long)w;
            if (cand < dist[v])
            {
                printf("Relaxing edge %d -> (%d -> %d) weight %d | %lld -> %lld\n", j, u, v, w, dist[v], cand);
                dist[v] = cand;
                changed = 1;
            }
        }

        if (!changed)
        {
            printf("No changes, stopping early.\n\n");
            break;
        }

        printf("\n");
    }

    printf("\nChecking for negative cycles...\n");

    for (int j = 0; j < E; ++j)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] == LLONG_MAX)
            continue;

        if (dist[u] + w < dist[v])
        {
            printf("Negative cycle detected!\n");

            free(edges);
            free(dist);
            return 0;
        }
    }

    printf("\n--- FINAL SHORTEST DISTANCES ---\n");
    for (int i = 0; i < V; ++i)
    {
        if (dist[i] == LLONG_MAX)
            printf("%d : INF\n", i);
        else
            printf("%d : %lld\n", i, dist[i]);
    }

    free(edges);
    free(dist);
    return 0;
}

/* Input Details

// Enter number of vertices and edges (V E): 5 8

// --- Graph Info ---
// Vertices: 5
// Edges: 8

// Enter 8 edges in format: u v w
// Example: 0 1 -3 means edge from 0 to 1 weight -3

// Edge 0: 0 1 -1
// Edge 1: 0 2 4
// Edge 2: 1 2 3
// Edge 3: 1 3 2
// Edge 4: 1 4 2
// Edge 5: 3 2 5
// Edge 6: 3 1 1
// Edge 7: 4 3 -3

// Enter source vertex (0 to 4): 0

*/