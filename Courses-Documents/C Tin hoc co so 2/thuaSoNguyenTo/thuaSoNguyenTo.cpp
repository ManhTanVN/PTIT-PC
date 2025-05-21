#include <stdio.h>
#include <math.h>

void factorize(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        //Neu n chia het cho i, i se la thua so nguyen to
        while (n % i == 0) {
            printf("%d ", i);
            n /= i; // n se giam 
        }
    }
    if (n > 1) {
        printf("%d", n);
    }
}

int main() {
    factorize(81);
    return 0;
}