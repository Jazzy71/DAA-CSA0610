#include <stdio.h>

// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    int sum = 0;

    while (num != 0) {
        sum += num % 10; // Add the last digit to sum
        num /= 10;       // Remove the last digit
    }

    return sum;
}

int main() {
    int num;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Ensure the number is positive
    if (num < 0) {
        num = -num;
    }

    // Calculate and print the sum of digits
    printf("Sum of digits: %d\n", sumOfDigits(num));

    return 0;
}

