#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20

// Structure to store information about a node
typedef struct {
    int cost;              // Cost of the node
    int assigned[MAX];     // Array to track assigned tasks
    int totalCost;         // Total cost of the solution
    int level;             // Level in the decision tree
    int task;              // Task assigned at this level
} Node;

// Function to find the minimum cost for a given row
int findMin(int costMatrix[MAX][MAX], int n, int row) {
    int min = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (costMatrix[row][j] < min) {
            min = costMatrix[row][j];
        }
    }
    return min;
}

// Function to calculate the reduced cost matrix and its cost
int reduceCostMatrix(int costMatrix[MAX][MAX], int n) {
    int reductionCost = 0;

    // Row reduction
    for (int i = 0; i < n; i++) {
        int rowMin = findMin(costMatrix, n, i);
        if (rowMin != INT_MAX && rowMin != 0) {
            reductionCost += rowMin;
            for (int j = 0; j < n; j++) {
                if (costMatrix[i][j] != INT_MAX) {
                    costMatrix[i][j] -= rowMin;
                }
            }
        }
    }

    // Column reduction
    for (int j = 0; j < n; j++) {
        int colMin = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (costMatrix[i][j] < colMin) {
                colMin = costMatrix[i][j];
            }
        }
        if (colMin != INT_MAX && colMin != 0) {
            reductionCost += colMin;
            for (int i = 0; i < n; i++) {
                if (costMatrix[i][j] != INT_MAX) {
                    costMatrix[i][j] -= colMin;
                }
            }
        }
    }

    return reductionCost;
}

// Branch and Bound to solve the Assignment Problem
void branchAndBound(int costMatrix[MAX][MAX], int n) {
    Node root;
    root.cost = 0;
    root.totalCost = reduceCostMatrix(costMatrix, n);
    root.level = 0;

    // Initialize the assignment array
    for (int i = 0; i < n; i++) {
        root.assigned[i] = -1;
    }

    // Priority queue for Branch and Bound
    Node queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int minCost = INT_MAX;
    Node solution;

    while (front < rear) {
        Node current = queue[front++];
        if (current.level == n) {
            if (current.totalCost < minCost) {
                minCost = current.totalCost;
                solution = current;
            }
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (current.assigned[i] == -1) {
                Node child = current;
                child.level = current.level + 1;
                child.task = i;
                child.assigned[current.level] = i;

                // Create a copy of the cost matrix and update it
                int newMatrix[MAX][MAX];
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        newMatrix[x][y] = costMatrix[x][y];
                    }
                }

                // Invalidate the assigned row and column
                for (int x = 0; x < n; x++) {
                    newMatrix[current.level][x] = INT_MAX;
                    newMatrix[x][i] = INT_MAX;
                }
                newMatrix[i][current.level] = INT_MAX;

                child.totalCost = current.totalCost + costMatrix[current.level][i] +
                                  reduceCostMatrix(newMatrix, n);

                queue[rear++] = child;
            }
        }
    }

    // Print the solution
    printf("Optimal Cost: %d\n", minCost);
    printf("Task Assignment:\n");
    for (int i = 0; i < n; i++) {
        printf("Agent %d -> Task %d\n", i + 1, solution.assigned[i] + 1);
    }
}

int main() {
    int n;
    int costMatrix[MAX][MAX];

    // Input the number of agents/tasks
    printf("Enter the number of agents/tasks: ");
    scanf("%d", &n);

    // Input the cost matrix
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    // Solve the assignment problem using Branch and Bound
    branchAndBound(costMatrix, n);

    return 0;
}

