#include <stdio.h>

// Function to calculate the binomial coefficient using recursion
int binomialCoeff(int n, int k) {
    // Base case: the first and last element of each row is 1
    if (k == 0 || k == n)
        return 1;
    // Recursive case: use the recursive formula
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

// Function to print Pascal's Triangle
void printPascal(int n) {
    for (int i = 0; i < n; i++) {
        // Print leading spaces to form the triangle shape
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        // Print the elements in the current row
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoeff(i, j));
        }
        printf("\n");
    }
}

int main() {
    int n;
    
    // Input number of rows for Pascal's Triangle
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    // Print Pascal's Triangle
    printPascal(n);
    
    return 0;
}

