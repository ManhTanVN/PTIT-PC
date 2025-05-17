#include <stdio.h>

long long lt(int a, int b) {
    long long res = 1;
    while (b != 0) {
        if (b % 2 != 0) {
            res *= a;
        }
        a *= a;
        b /= 2;
    }
    return res;
}

int main()
{
    int a, b;
    scanf_s("%d %d", &a, &b);
    printf_s("ket qua lua thua cua a mu b la %lld\n", lt(a, b));
    return 0;
}
