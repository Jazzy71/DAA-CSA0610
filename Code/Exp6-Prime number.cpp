#include <stdio.h>

int isPrime(int num, int divisor) {
    if (num <= 2) {
        return (num == 2) ? 1 : 0;  
    }
    if (num % divisor == 0) {
        return 0; 
    }
    if (divisor * divisor > num) {
        return 1;  
    }
    return isPrime(num, divisor + 1);  
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Negative numbers cannot be prime.\n");
    } else if (isPrime(num, 2)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}

