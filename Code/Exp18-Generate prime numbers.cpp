#include <stdio.h>
int isPrime(int n, int i) {
    if (n <= 2) return (n == 2);
    if (n % i == 0) return 0;
    if (i * i > n) return 1;
    return isPrime(n, i + 1);
}
void generatePrimes(int n) {
    if (n < 2) return;
    generatePrimes(n - 1);
    if (isPrime(n, 2)) printf("%d ", n);
}
int main() {
    int n = 20;
    generatePrimes(n);
    return 0;
}
