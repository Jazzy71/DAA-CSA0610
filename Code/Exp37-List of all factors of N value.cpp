#include <stdio.h>

// Recursive function to print all factors of n
void printFactors(int n, int current) {
    // Base case: Stop recursion when current exceeds n
    if (current > n) {
        return;
    }

    // Check if current is a factor of n
    if (n % current == 0) {
        printf("%d ", current);
    }

    // Recursive call with incremented current
    printFactors(n, current + 1);
}

int main() {
    int n;

    // Input the value of n
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 0;
    }

    printf("Factors of %d are: ", n);
    // Start the recursive function with current = 1
    printFactors(n, 1);

    return 0;
}

