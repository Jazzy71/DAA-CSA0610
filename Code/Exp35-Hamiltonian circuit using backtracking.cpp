#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int path[MAX]; // Stores the Hamiltonian circuit path

// Function to check if the vertex can be added to the current path
bool isSafe(int v, int graph[MAX][MAX], int path[], int pos) {
    // Check if the vertex is adjacent to the last vertex in the path
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    // Check if the vertex is already in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

// Recursive utility function to find the Hamiltonian Circuit
bool hamiltonianCycleUtil(int graph[MAX][MAX], int path[], int pos, int n) {
    // Base case: If all vertices are included in the path
    if (pos == n) {
        // Check if the last vertex is adjacent to the first vertex
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try different vertices as the next candidate
    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamiltonianCycleUtil(graph, path, pos + 1, n)) {
                return true;
            }

            // Backtrack: Remove the vertex from the path
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find and print the Hamiltonian Circuit
void hamiltonianCycle(int graph[MAX][MAX], int n) {
    // Initialize the path
    for (int i = 0; i < n; i++) {
        path[i] = -1;
    }

    // Start from the first vertex
    path[0] = 0;

    if (!hamiltonianCycleUtil(graph, path, 1, n)) {
        printf("No Hamiltonian Circuit exists.\n");
        return;
    }

    // Print the Hamiltonian Circuit
    printf("Hamiltonian Circuit:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", path[i]);
    }
    printf("%d\n", path[0]); // Return to the starting vertex
}

int main() {
    int n;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Find and print the Hamiltonian Circuit
    hamiltonianCycle(graph, n);

    return 0;
}

