#include <stdio.h>
#define MAX 100

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void xuat(int a[], int n, int i) {
    printf("Buoc %d:", i);
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

void snchon(int a[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (i != min) {
            swap(&a[min], &a[i]);
        }
        xuat(a, n, i + 1);
        printf("\n");
    }
}

int main() {
    int n, i, a[MAX];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    snchon(a, n);
    return 0;
}