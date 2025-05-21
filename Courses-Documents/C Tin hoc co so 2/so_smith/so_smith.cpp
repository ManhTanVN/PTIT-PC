// so_smith.cpp : This file contains the 'main' function. Program execution begins and ends there.
// input n
// n khong la so nguyen to
// tong cac uoc nguyen to cua n thi bang n
// input 22
// out put NO
//

#include <stdio.h>
#include <math.h>

static int tong_chu_so(long long n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
static void so_smith(long long n) {
    if (n < 2) {      
        printf_s("NO\n");
    }
    long long ori = n;
    int sum = 0;
    int temp = tong_chu_so(n);

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                sum += tong_chu_so(i);
                n /= i;
            }
        }
    }
    if (n != 1 && n != ori) {
        sum += tong_chu_so(n);
    }
    if (sum == temp) {
        printf_s("YES\n");
    }
    else {
        printf_s("NO\n");
    }
    printf_s("%d -- %d\n", sum, temp);
}

int main()
{
    int s;
    printf_s("So lan thu\n");
    scanf_s("%d", &s);
      
    for (int i = 0; i < s; i++) {
        long long n;
        printf_s("nhap so kiem tra\n");    
        scanf_s("%lld", &n);
        so_smith(n);
        
    }
    return 0;
}
