#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

// Function to subtract row minimums
void subtractRowMins(int costMatrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        int minVal = INF;
        for (int j = 0; j < n; j++) {
            if (costMatrix[i][j] < minVal) {
                minVal = costMatrix[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            costMatrix[i][j] -= minVal;
        }
    }
}

// Function to subtract column minimums
void subtractColMins(int costMatrix[MAX][MAX], int n) {
    for (int j = 0; j < n; j++) {
        int minVal = INF;
        for (int i = 0; i < n; i++) {
            if (costMatrix[i][j] < minVal) {
                minVal = costMatrix[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            costMatrix[i][j] -= minVal;
        }
    }
}

// Function to cover zeros in the matrix
void coverZeros(int costMatrix[MAX][MAX], int n, int rowCover[MAX], int colCover[MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (costMatrix[i][j] == 0 && !rowCover[i] && !colCover[j]) {
                rowCover[i] = 1;
                colCover[j] = 1;
                break;
            }
        }
    }
}

// Function to find the optimal assignment using the Hungarian algorithm
int hungarianAlgorithm(int costMatrix[MAX][MAX], int n) {
    int rowCover[MAX] = {0}, colCover[MAX] = {0};
    int assign[MAX] = {0};

    // Step 1: Subtract the row minimum
    subtractRowMins(costMatrix, n);

    // Step 2: Subtract the column minimum
    subtractColMins(costMatrix, n);

    // Step 3: Cover all zeros
    coverZeros(costMatrix, n, rowCover, colCover);

    // Step 4: Repeat steps until a valid assignment is found
    int minCost = 0;
    for (int i = 0; i < n; i++) {
        int minValue = INF;
        for (int j = 0; j < n; j++) {
            if (costMatrix[i][j] == 0 && !colCover[j]) {
                assign[i] = j;
                minCost += costMatrix[i][j];
                break;
            }
        }
    }

    return minCost;
}

int main() {
    int n;

    // Input the number of tasks/agents
    printf("Enter the number of tasks/agents: ");
    scanf("%d", &n);

    // Input the cost matrix
    int costMatrix[MAX][MAX];
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    // Compute the optimal cost using the Hungarian algorithm
    int optimalCost = hungarianAlgorithm(costMatrix, n);

    // Output the optimal cost
    printf("The optimal cost is: %d\n", optimalCost);

    return 0;
}

