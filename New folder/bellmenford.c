#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10 // Maximum number of vertices in the graph

int main() {
    int n; // Number of vertices in the graph
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix of the graph
    printf("Enter the adjacency matrix of the graph (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src; // Source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    int dist[MAX_VERTICES]; // Array to store shortest distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0; // Distance from source to itself is 0

    // Dijkstra's algorithm with cycle detection
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] != 0) { // Edge exists between vertices i and j
                    if (dist[i] != INT_MAX && dist[i] + graph[i][j] < dist[j]) {
                        dist[j] = dist[i] + graph[i][j];
                        // Check for negative weight cycle
                        if (s == n - 1) {
                            printf("Graph contains negative weight cycle.\n");
                            return 0;
                        }
                    }
                }
            }
        }
    }

    // Printing shortest distances from source vertex
    printf("\nShortest distances from source vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: Distance %d\n", i, dist[i]);
    }

    return 0;
}