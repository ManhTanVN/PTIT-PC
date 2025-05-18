// boi_chung_nho_nhat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

#define ll long long

// Uoc chung lon nhat
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
// Boi chung nho nhat
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}


int main()
{
    ll a, b;
    scanf_s("%lld %lld", &a, &b);
    printf_s("%lld\n", gcd(a, b));
    printf_s("%lld\n", lcm(a, b));
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
