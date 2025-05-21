#include <stdio.h>
#define MAX 100

void xuatkq(int a[], int n, int i) {
    int j;
    printf("Buoc %d:", i);
    for (j = 0; j <= i; j++) {
        printf("%3d", a[j]);
    }
    printf("\n");
}

void sxchen(int a[], int n) {
    int i, j, x;
    printf("Buoc 0:%3d\n", a[0]);
    for (i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;
        while (x < a[j] && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
        xuatkq(a, n, i);
    }
}

int main() {
    int n, i, a[MAX];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sxchen(a, n);
    return 0;
}