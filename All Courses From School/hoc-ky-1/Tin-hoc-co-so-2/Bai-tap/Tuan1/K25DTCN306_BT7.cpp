#include <stdio.h>

int main() {
    int a = 5, b = 7;
    double c = 4.5, d = 6;

    printf("%d + %f = %f \n", a, c, a + c);
    printf("%d - %d = %d \n", a, b, a - b);
    printf("%d * %f = %f \n", b, d, b * d);

    /* Luu y phep chia nhe */
    printf("%d / %d = %d \n", b, a, b / a);
    printf("%f / %d = %f \n", c, a, c / a);
    printf("%f / %f = %f \n", c, d, c / d);
    printf("%d %% %d = %d \n", b, a, b % a);

    return 0;
}

