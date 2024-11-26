#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10
#define INF INT_MAX

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    // dist[][] will hold the shortest distance between every pair of vertices
    int dist[MAX_VERTICES][MAX_VERTICES];

    // Initialize the distance matrix with graph values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0 && i != j) {
                dist[i][j] = INF; // No path between different vertices
            } else {
                dist[i][j] = graph[i][j]; // Distance between i and j
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Update the shortest distance if a shorter path is found
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printf("Shortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix (graph representation)
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (0 for no edge, other numbers for edge weight):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run Floyd-Warshall algorithm
    floydWarshall(graph, n);

    return 0;
}

