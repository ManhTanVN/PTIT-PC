#include <stdio.h>

int main() {
    int x;

    x = 5;
    printf("x = 5 => x = %d\n", x);

    x += 5;
    printf("x += 5 => x = %d\n", x);

    x -= 5;
    printf("x -= 5 => x = %d\n", x);

    x *= 5;
    printf("x *= 5 => x = %d\n", x);

    x /= 5;
    printf("x /= 5 => x = %d\n", x);

    return 0;
}

