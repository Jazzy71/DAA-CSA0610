#include <stdio.h>

// Function to reverse the number
int reverse(int n, int rev) {
    // Base case: when the number becomes 0
    if (n == 0) {
        return rev;
    }
    // Recursive case: extract last digit and append to rev
    return reverse(n / 10, rev * 10 + n % 10);
}

int main() {
    int num;

    // Input the number to be reversed
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the reverse function
    int reversed = reverse(num, 0);

    // Output the reversed number
    printf("Reversed number is: %d\n", reversed);

    return 0;
}

