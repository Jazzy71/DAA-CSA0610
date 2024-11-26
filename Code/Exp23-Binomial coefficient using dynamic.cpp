#include <stdio.h>

#define MAX 100

// Function to compute binomial coefficient C(n, k) using dynamic programming
int binomialCoefficient(int n, int k) {
    int dp[MAX][MAX];

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;  // Base case: C(n, 0) = C(n, n) = 1
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];  // Recursive relation
            }
        }
    }

    // Return the binomial coefficient C(n, k)
    return dp[n][k];
}

int main() {
    int n, k;

    // Input values for n and k
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Compute and display the binomial coefficient C(n, k)
    printf("Binomial Coefficient C(%d, %d) is %d\n", n, k, binomialCoefficient(n, k));

    return 0;
}

