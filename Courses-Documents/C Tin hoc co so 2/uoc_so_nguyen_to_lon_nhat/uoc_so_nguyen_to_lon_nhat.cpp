// uoc_so_nguyen_to_lon_nhat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <math.h>

int uoc_so_nguyen_to_lon_nhat(long long n) {
    int res = -1;
    if (n < 2) return -1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                res = i;
            }
        }
    }
    if (n != 1) {
        res = n;
    }
    return res;
}
int main()
{
    long long n,m,l;
    printf_s("Moi nhap 3 so can kiem tra\n");
    scanf_s("%lld %lld %lld", &l,&m,&n);
    printf_s("uoc_so_nguyen_to_lon_nhat cua %lld: %d\n",l, uoc_so_nguyen_to_lon_nhat(l));
    printf_s("uoc_so_nguyen_to_lon_nhat cua %lld: %d\n",m, uoc_so_nguyen_to_lon_nhat(m));
    printf_s("uoc_so_nguyen_to_lon_nhat cua %lld: %d\n",n, uoc_so_nguyen_to_lon_nhat(n));
    return 0;
}
