#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Function to print the solution
void printSolution(int color[], int n) {
    printf("Vertex -> Color\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", i + 1, color[i]);
    }
    printf("\n");
}

// Function to check if it's safe to assign color c to vertex v
bool isSafe(int v, int graph[MAX][MAX], int color[], int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c) { // If adjacent vertex has the same color
            return false;
        }
    }
    return true;
}

// Recursive utility function to solve the graph coloring problem
bool graphColoringUtil(int graph[MAX][MAX], int m, int color[], int v, int n) {
    // If all vertices are assigned a color, return true
    if (v == n) {
        printSolution(color, n);
        return true;
    }

    // Try all colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1, n)) {
                return true;
            }

            // Backtrack: Remove color assignment
            color[v] = 0;
        }
    }

    return false; // If no color can be assigned to this vertex
}

// Function to solve the graph coloring problem
void graphColoring(int graph[MAX][MAX], int m, int n) {
    int color[MAX] = {0}; // Array to store colors of vertices

    if (!graphColoringUtil(graph, m, color, 0, n)) {
        printf("Solution does not exist with %d colors.\n", m);
    }
}

int main() {
    int n, m;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    int graph[MAX][MAX];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Solve the graph coloring problem
    printf("Graph Coloring Solution:\n");
    graphColoring(graph, m, n);

    return 0;
}

