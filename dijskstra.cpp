#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 9
// Function that implement Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation

/* int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
} */

void dijkstra(int graph[V][V], int src)
{
    // The output array. dist[i] will hold the shortest distance from src to i
    int dist[V];

    // sptSet[i] will true if vertex i is included in shortest path tree
    // or shortest distance from src to i is finalized.
    bool sptSet[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        printf("count = %d\n", count);
        // u is always equal to src in first iteration
        int u;
        int min = INT_MAX;
        // Pick the minimum distance vertex from the set of vertices not yet
        // processed.
        for (int v = 0; v < V; v++)
        {
            printf("loop mindistance,sptSet[%d] = %d, dist[%d] = %d\n", v, sptSet[v], v, dist[v]);

            if (sptSet[v] == false && dist[v] <= min)
            {
                min = dist[v];
                u = v;
                printf("update min = %d, sptset[%d] == false, dist[%d] = %d <= min \n", min, v, v, dist[v]);
            }
        }

        // Mark the picked vertex as processed
        sptSet[u] = true;
        printf("Mark the picked vertex as processed, sptSet[%d] = %d\n", u, sptSet[u]);
        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
        {
            printf("loop dist value of the adjacent vertices of the picked vertex\n");
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v,
            // and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            printf(" loop v = %d, sptSet[%d] = %d, dist[%d] = %d, graph[%d][%d] = %d\n", v,v,sptSet[v], v, dist[v], u, v, graph[u][v]);
            if (!sptSet[v] &&
                graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
               printf(" update dist[%d] = %d, graph[%d][%d] = %d\n", v, dist[v], u, v, graph[u][v]);
            }
        }

    }
    // print the constructed distance array
    printf("Vertex Distance from sourcen");
    for (int i = 0; i < V; i++)
        printf("%d \t \t %d\n", i, dist[i] );
}


// driver program to test above function
int main()
{
    // Let us create the example graph discussed above
    int graph[V][V] = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0},
    };
    dijkstra(graph, 0);
}
