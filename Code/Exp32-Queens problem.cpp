#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Function to print the solution
void printSolution(int board[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    int i, j;

    // Check the same column
    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Check the upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the upper-right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive utility function to solve the N-Queens problem
bool solveNQueens(int board[MAX][MAX], int row, int n) {
    // Base case: If all queens are placed, return true
    if (row >= n) {
        printSolution(board, n);
        return true;
    }

    bool success = false;

    // Try placing a queen in all columns of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the remaining queens
            success = solveNQueens(board, row + 1, n) || success;

            // Backtrack: Remove the queen
            board[row][col] = 0;
        }
    }

    return success;
}

int main() {
    int n;

    // Input the size of the chessboard
    printf("Enter the value of N (size of the chessboard): ");
    scanf("%d", &n);

    int board[MAX][MAX] = {0};

    // Solve the N-Queens problem
    if (!solveNQueens(board, 0, n)) {
        printf("No solution exists for %d Queens.\n", n);
    }

    return 0;
}

