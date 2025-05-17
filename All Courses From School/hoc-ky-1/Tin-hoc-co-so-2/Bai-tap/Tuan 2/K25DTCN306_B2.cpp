#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b) {
        printf("a lon hon b");
        printf("\n a=%d b=%d", a, b);
    } else {
        printf("\n a nho hon hoac bang b", a);
        printf("\n a=%d b=%d", a, b);
    }
    printf("\n Thuc hien xong lenh if");
    return 0;
}
