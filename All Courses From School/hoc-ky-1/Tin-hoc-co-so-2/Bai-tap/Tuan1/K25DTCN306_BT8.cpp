#include <stdio.h>

int main() {
    int a = 5, b = 7;
    double c;

    printf("%d / %d = %d \n", b, a, b / a);

    /* Chuyen gia tri tuc thoi cua b sang kieu so thuc */
    printf("%d / %d = %f \n", b, a, (double)b / a);

    /* Chuyen gia tri tuc thoi cua a sang kieu so thuc */
    printf("%d / %d = %f \n", b, a, b / (double)a);

    /* Neu lam the nay thi van khong dung, vi b/a duoc so nguyen
       sau do chung ta moi ep kieu so nguyen do sang so thuc */
    printf("%d / %d = %f \n", b, a, (double)(b / a));

    return 0;
}

