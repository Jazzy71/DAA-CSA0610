#include <stdio.h>

// Function to check if a number is a perfect number
int isPerfect(int n) {
    int sum = 0;

    // Find divisors of n and calculate their sum
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    // A number is perfect if the sum of its divisors equals the number itself
    return (sum == n);
}

int main() {
    int num;

    // Input the number to check
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check and display whether the number is perfect
    if (isPerfect(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}

