# 과제 2) 피보나치 복잡도 프로파일링 보고서

## 1. 과제 개요
- **목표**: 재귀 방식으로 구현한 피보나치 수열 `F(n)`과 그 전값 `F(n‑1)`에 대해 유클리드 알고리즘(GCD)을 수행하면서 CPU 시간 및 메모리 사용량을 프로파일링한다.  
- **환경**: C 언어, `time.h`의 `clock()` 함수 (Visual Studio 프로파일러 사용이 불가능한 경우)  
- **핵심 결과**: 실행 시간이 지수적으로 증가함을 확인하고, 이론적인 시간 복잡도 `O(2^n)`(피보나치)와 `O(log n)`(GCD)을 검증한다.

---

## 2. 사용한 소스 코드 (`fibonacci_profiling.c`)

```c
#include <stdio.h>
#include <time.h>

// ① 재귀 피보나치 함수
long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// ② 유클리드 GCD 함수
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    printf("n\tF(n)\t\tTime(s)\n");
    printf("------------------------------------\n");

    for (int n = 5; n <= 40; n++) {
        clock_t start = clock();

        long long fn        = fibonacci(n);       // F(n)
        long long fn_1      = fibonacci(n - 1);   // F(n‑1)
        long long result_gcd = gcd(fn, fn_1);      // GCD(F(n),F(n‑1))

        clock_t end = clock();
        double secs = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%lld\t\t%.6f\n", n, fn, secs);

        // 실행 시간이 너무 오래 걸리면 중단 (환경에 따라 조정)
        if (secs > 5.0) break;
    }
    return 0;
}

