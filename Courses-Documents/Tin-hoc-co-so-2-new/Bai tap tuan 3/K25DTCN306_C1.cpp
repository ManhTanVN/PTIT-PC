#include <stdio.h>
#define MAX 100

void botrungnhau(int a[], int n) {
    int i, b[MAX] = { 0 };

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i]]++;
    }

    for (i = 0; i < n; i++) {
        if (b[a[i]] >= 1) {
            printf("%3d ", a[i]);
            b[a[i]] = 0;
        }
    }
}

int main() {
    int n, a[MAX];
    scanf("%d", &n);
    botrungnhau(a, n);
    return 0;
}