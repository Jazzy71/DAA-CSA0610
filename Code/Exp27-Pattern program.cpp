#include <stdio.h>

// Recursive function to print numbers from 1 to current row
void printNumbers(int current) {
    // Base case: if current exceeds row number, return
    if (current > 0) {
        printNumbers(current - 1);  // Recursive call for previous numbers
        printf("%d ", current);     // Print the current number
    }
}

// Recursive function to print the pattern
void printPattern(int n, int row) {
    // Base case: if row exceeds n, stop the recursion
    if (row > n) {
        return;
    }

    // Print numbers from 1 to the current row
    printNumbers(row);
    printf("\n");

    // Recursive call for the next row
    printPattern(n, row + 1);
}

int main() {
    int n;

    // Input the number n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Start the recursion with row 1
    printPattern(n, 1);

    return 0;
}

