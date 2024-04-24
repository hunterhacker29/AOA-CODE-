#include <stdio.h>
#include <stdbool.h> // Include this for boolean type
#include <stdlib.h> // Include this for malloc()

#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    bool visited[MAX]; // Changed to boolean type
    int count, mindistance, nextnode, i, j; // Corrected variable declarations

    // Initialize cost matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0) {
                cost[i][j] = INFINITY;
            } else {
                cost[i][j] = G[i][j]; // Corrected assignment
            }
        }
    }

    // Initialize distance, pred, and visited arrays
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = false; // Changed to boolean type
    }

    distance[startnode] = 0;
    visited[startnode] = true; // Changed to boolean type

    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;

        // Find the next closest unvisited node
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = true; // Changed to boolean type

        // Update distances of neighboring nodes
        for (i = 0; i < n; i++) {
            if (!visited[i] && cost[nextnode][i] != INFINITY && 
                distance[nextnode] + cost[nextnode][i] < distance[i]) {
                distance[i] = distance[nextnode] + cost[nextnode][i];
                pred[i] = nextnode;
            }
        }

        count++;
    }

    // Print the shortest distances and paths
    printf("Shortest distances from node %d:\n", startnode);
    for (i = 0; i < n; i++) {
        printf("Node %d: Distance %d\n", i, distance[i]);
    }

    printf("\nPaths:\n");
    for (i = 0; i < n; i++) {
        if (i != startnode) {
            printf("Path to node %d: ", i);
            j = i;
            do {
                j = pred[j];
                printf("%d <- ", j);
            } while (j != startnode);
            printf("%d\n", startnode);
        }
    }
}

int main() {
    int G[MAX][MAX], i, j, n, u; // Corrected variable declaration

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &u);

    dijkstra(G, n, u);

    return 0;
}
