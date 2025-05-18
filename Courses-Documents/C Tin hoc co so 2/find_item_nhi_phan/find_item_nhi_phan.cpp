// dequy_find_item_nhi_phan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int find(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x) 
            l = mid + 1;
        else if (a[mid] > x) 
            r = mid - 1;
        else
            return -1;
    }
}

int main()
{
    int n;
    scanf_s("%d", &n);
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    int x;
    scanf_s("%d", &x);
    //for (int i = 0; i < n; i++) {
    //    printf_s("value: %d", a[i]);
    //}
     int idx = find(a, n, x);
     printf_s("index: %d\n", idx);

    return 0;
}