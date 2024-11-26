#include <stdio.h>

int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  
            } else if (weights[i - 1] <= w) {
                                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) 
                           ? values[i - 1] + dp[i - 1][w - weights[i - 1]] 
                           : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w]; 
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    int maxValue = knapsack(W, weights, values, n);
    printf("The maximum value that can be put in the knapsack is: %d\n", maxValue);

    return 0;
}

