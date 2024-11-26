#include <stdio.h>
#include <limits.h>

#define MAX 20

// Function to calculate the sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int total = 0;
    for (int k = i; k <= j; k++) {
        total += freq[k];
    }
    return total;
}

// Function to find the optimal binary search tree using dynamic programming
int optimalBST(int keys[], int freq[], int n) {
    // cost[i][j] will store the optimal cost of BST with keys[i..j]
    int cost[MAX][MAX];

    // Initialize cost for single key subtrees
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Loop for chain length
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;

            // Try all roots for the current subtree
            for (int r = i; r <= j; r++) {
                int leftCost = (r > i) ? cost[i][r - 1] : 0;
                int rightCost = (r < j) ? cost[r + 1][j] : 0;
                int totalCost = leftCost + rightCost + sum(freq, i, j);

                if (totalCost < cost[i][j]) {
                    cost[i][j] = totalCost;
                }
            }
        }
    }

    // Return the optimal cost for the entire range (0 to n-1)
    return cost[0][n - 1];
}

int main() {
    int n;

    // Input number of keys
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    // Input the keys (not really needed for cost calculation but for display)
    int keys[n];
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    // Input the frequencies or probabilities of the keys
    int freq[n];
    printf("Enter the frequencies for the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    // Calculate and print the optimal cost
    int optimalCost = optimalBST(keys, freq, n);
    printf("The minimum cost of constructing the Optimal Binary Search Tree is: %d\n", optimalCost);

    return 0;
}

