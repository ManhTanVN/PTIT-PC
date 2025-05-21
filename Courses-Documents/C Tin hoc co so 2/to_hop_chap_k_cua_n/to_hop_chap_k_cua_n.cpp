// to_hop_chap_k_cua_n.cpp : This file contains the 'main' function. Program execution begins and ends there.
// n = 0 || n = k => C(n,k) = 1
// CT pascal: C(n,k) = C(n -1, k -1) + C(n -1, k -1)
//

#include <stdio.h>

int C(int n,int k) {
    if (n == k || k == 0) return 1;
    else
        return C(n - 1, k - 1) + C(n - 1, k - 1);
}
int main()
{
    int n,k;
    scanf_s("%d %d", &n, &k);
    printf_s("%d\n", C(n,k));
    return 0;
}
