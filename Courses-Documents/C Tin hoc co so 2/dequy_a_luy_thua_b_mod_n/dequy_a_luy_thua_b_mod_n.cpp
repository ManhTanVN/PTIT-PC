// dequy_a_luy_thua_b_mod_n.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// (a * b) mod n = ((a mod n) * (a mo n) mod n)
// a luy thua b mod n = 
// 1. (a luy thua b /2 mod n)^2 mod n =>> b la chan (even)
// 2. ((a luy thua b /2 mod n)^2 mod n) * a mod n =>> b la le (odd)
//

#include <stdio.h>
#define ll long long

const int mod_n = 10000000007;

ll a_luythua_b_modN(ll a, ll b) {
    if (b == 0)
        return 1;
    ll temp = a_luythua_b_modN(a, b / 2);

    if (b % 2 == 0)
        return ((temp % mod_n) * (temp % mod_n)) % mod_n;
    else
        return ((temp % mod_n) * (temp % mod_n) * a % mod_n) % mod_n;
}

int main()
{
    ll a, b;
    scanf_s("%lld %lld", &a, &b);
    printf_s("%lld\n", a_luythua_b_modN(a, b));
    return 0;
}
