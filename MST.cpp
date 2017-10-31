#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 9
// Function that implement Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation

/* int minKey(int key[], bool MSTSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (MSTSet[v] == false && key[v] <= min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
} */

void PrimMST(int graph[V][V])
{
    // Key values used to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices not yet included in MST
    bool  MSTSet[V];

    // Array to store constructed MST
    int parent[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        MSTSet[i] = false;
    }

    // Always include first lst vertex in MST
    key[0] = 0;
    parent[0] = -1;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        printf("count = %d\n", count);

        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u;
        int min = INT_MAX;
        for (int v = 0; v < V; v++)
        {
            if (MSTSet[v] == false && key[v] <= min)
            {
                min = MSTSet[v];
                u = v;
            }
        }

        // Mark the picked vertex as processed
        MSTSet[u] = true;
        // Update key value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
        {
            if (!MSTSet[v] &&
                graph[u][v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }

    }
    // print the constructed distance array
    for (int i = 0; i < V; i++)
        printf("%d -  %d\t %d\n", parent[i],i, graph[i][parent[i]]);
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
    PrimMST(graph);
}
