#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "fib.h"

int main() {
    int n;
    printf("n | F(n) | GCD | Time(s)\n");
    printf("-------------------------------\n");

    for (n = 5; n <= 40; n++) {
        clock_t start = clock();

        long long fn = fibonacci(n);
        long long fn1 = fibonacci(n - 1);
        long long common_divisor = gcd(fn, fn1);

        clock_t end = clock();
        double duration = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d | %lld | %lld | %f\n", n, fn, common_divisor, duration);
    }
    return 0;
}
