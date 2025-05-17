#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf_s("%d", &n);
    int sum = 0;
    int sum2 = 0;
    for (int i = 1; i <=  sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (n / i != i)
                sum += n / i;   
        }
    }
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            sum2 += i;
        }
    }
    printf_s("%d %d", sum, sum2);
    return 0;
}
