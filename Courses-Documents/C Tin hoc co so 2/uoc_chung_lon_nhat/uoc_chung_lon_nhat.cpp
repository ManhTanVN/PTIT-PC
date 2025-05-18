// uoc_chung_lon_nhat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

long long uoc(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return uoc(b, a % b);
}
int main()
{
    long long a, b;
    scanf_s("%lld %lld", &a, &b);
    printf_s("%lld", uoc(a, b));
    return 0;
}
