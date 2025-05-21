// dequy_a_luythua_b.cpp : This file contains the 'main' function. Program execution begins and ends there.'
// a ^ b
// b = 0 --> 1
// b chan --> a^b/2 * a^b/2
// b le --> a^b/2 * a^b/2 * a
//

#include <stdio.h>
#define ll long long

// a luy thua b
ll luythua(ll a, ll b) {
    if (b == 0)
        return 1;
    //printf_s("test\n");
    ll temp = luythua(a, b / 2);
    //printf_s("%lld -- %lld\n", temp, b);
    if (b % 2 == 0)
        return temp * temp;
    else
        return temp * temp * a;
}


ll luythua_2(ll a, ll b) {
    if (b == 0)
        return 1;
    return a * luythua_2(a, b - 1);
}
int main()
{
    ll a, b;
    scanf_s("%lld %lld", &a, &b);
    printf_s("%lld\n", luythua(a, b));
    printf_s("%lld\n", luythua_2(a, b));
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
