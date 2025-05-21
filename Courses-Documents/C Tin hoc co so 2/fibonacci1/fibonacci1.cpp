// fibonacci1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// In ra n so fibonacci đầu tiên
// input 6
// out put 1, 1, 2, 3, 5, 8,
//

#include <stdio.h>
// Fibonacci ly thuyet
// k = n_k-1 + n_k-2
//
void fibonacci_1(int n) {
    long long n1 = 1,n2 = 1;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf_s("%lld", n1);
        }
        if (i == 2) {
            printf_s(", %lld", n2);
        }
        if (i > 2) {
            long long res = n2 + n1;
            n1 = n2;
            n2 = res;
            printf_s(", %lld", res);
        }
    }
}
int main()
{
    int n;
    scanf_s("%d", &n);
    fibonacci_1(n);
    return 0;
}
