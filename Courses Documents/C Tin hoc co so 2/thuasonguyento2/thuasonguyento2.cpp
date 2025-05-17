// thuasonguyento2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// in put 60
// out put: 2^2 * 3^1 * 5^1;
//

#include <stdio.h>
#include <math.h>

void thuasonguyento(long long n) {
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int mu = 0;
            while (n % i == 0) {
                n /= i;
                mu++;
            }
            printf_s("%lld^%d", i, mu);
            if (n != 1) {
                printf_s(" * ");
            }
            
        }
    }
    if (n > 1) {
        printf_s("%lld^1\n", n);
    }
}

int main()
{
    long long n;
    printf_s("Nhap so!\n");
    scanf_s("%lld", &n);
    thuasonguyento(n);
    return 0;
}