#include <stdio.h>
#include <math.h>

int sphenic(long long n) {
    int count = 0;
    for (long long i = 2; i <= sqrt(n); i++) {
        int count2 = 0;
        //Neu n chia het cho i, i se la thua so nguyen to
        while (n % i == 0) {
            //printf("%lld ", i);
            n /= i; // n se giam 
            count2++;
            if (count2 > 1) {
                return 0;
            }
        }
        count++;
    }
    if (n > 1) {
        //printf("%lld ", n);
        count++;
    }
    if (count == 3) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int a;
    scanf_s("%d", &a);
    printf_s("%d", sphenic(a));
    return 0;
}