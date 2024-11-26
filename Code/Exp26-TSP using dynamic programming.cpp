#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 16  // Maximum number of cities
#define INF INT_MAX  // Infinite cost (initialization)

int dist[MAX_CITIES][MAX_CITIES];  // Distance matrix
int dp[1 << MAX_CITIES][MAX_CITIES];  // DP table to store subproblem results

// Function to solve TSP using Dynamic Programming and Bitmasking
int tsp(int mask, int pos, int n) {
    // If all cities have been visited, return the distance to the start city
    if (mask == (1 << n) - 1) {
        return dist[pos][0];  // Return to the starting city
    }

    // If the result for this subproblem has already been computed, return it
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    // Try to go to every other city that hasn't been visited
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {  // If the city hasn't been visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, n);
            ans = (ans < newAns) ? ans : newAns;
        }
    }

    // Memoize the result and return
    dp[mask][pos] = ans;
    return ans;
}

int main() {
    int n;

    // Input the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input the distance matrix
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Initialize the dp table with -1 (indicating unvisited subproblems)
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    // Find the minimum cost using TSP with starting city 0
    int result = tsp(1, 0, n);

    // Output the minimum cost of the tour
    printf("The minimum cost of the TSP tour is: %d\n", result);

    return 0;
}

