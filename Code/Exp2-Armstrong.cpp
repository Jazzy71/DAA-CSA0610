#include <stdio.h>
#include <math.h>

int countDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return 1 + countDigits(num / 10);
}

int armstrongSum(int num, int n) {
    if (num == 0) {
        return 0;
    }
    int digit = num % 10;
    return pow(digit, n) + armstrongSum(num / 10, n);
}

int main() {
    int num, n, result;

    printf("Enter an integer: ");
    scanf("%d", &num);

    n = countDigits(num);

    result = armstrongSum(num, n);

    if (result == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}

