// dequy_find_item_nhi_phan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

//int find(int a[], int l, int r, int x) {
//    if (a[r / 2] == x)
//        return r / 2;
//    else {
//        if (l < r) {
//            int n_r = (r - l) / 2;
//            if (x < a[r / 2]) {
//                find(a, l, n_r - 1, x);
//            }
//            else {
//                find(a, n_r + 1,r , x);
//            }
//        }
//        else
//            return 0;
//    }
//}

int main()
{
    int n;
    scanf_s("%d", &n);
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    int x;
    scanf_s("%d", &x);
    for (int i = 0; i < n; i++) {
        printf_s("value: %d", a[i]);
    }
   /* int idx = find(a, 0, n - 1, x);
    printf_s("index: %d - value: %d\n", a[idx]);*/

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
