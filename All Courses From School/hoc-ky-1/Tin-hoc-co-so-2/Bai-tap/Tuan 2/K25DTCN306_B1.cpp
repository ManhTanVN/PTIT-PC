#include <stdio.h>

int main() {
    float a;
    scanf("%f", &a);
    if (a != 0)
        printf("Nghich dao cua %f la %f", a, 1 / a);
    else
        printf("Khong the tim duoc nghich dao cua a");
    return 0;
}
