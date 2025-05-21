// dequy_quicksort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int partition(int a[], int l, int r) {
    int i = l - 1, pivot = a[r];
    for (int j = l; j < r; j++) {
        // if a[j] > pivot => continue;
        if (a[j] <= pivot) {
            ++i;
            // exchange a[j] with a[i]
            int temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    ++i;
    // exchange a[r] with a[i]
    int temp = a[i]; a[i] = a[r]; a[r] = temp;
    return i;
}
void quicksort(int a[], int l, int r) {
    if (l < r) {
        int pos = partition(a, l, r);
        quicksort(a, l, pos - 1);
        quicksort(a, pos + 1, r);

    }
}
int main()
{
    int n;
    scanf_s("%d", &n);
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf_s("%d", a[i]);
    }
    return 0;
}
