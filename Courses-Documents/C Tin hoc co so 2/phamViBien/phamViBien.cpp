#include <stdio.h>

int glo = 100;
void custom() {
    glo = 300;
}
void custom2() {
    printf_s("local 2 %d\n", glo);
}
int main()
{
    //int i;
    //for (i = 0; i < 10; i++) {
    //    printf_s("Trong pham vi ham for %d\n", i);
    //    if (i == 9) continue;
    //}
    //printf_s("Ngoai pham vi ham for %d\n", i);

    //int n = 0;
    //if (n == 0) {
    //    n = 3;
    //    printf_s("Trong pham vi ham IF %d\n", n);
    //}
    //printf_s("Ngoai pham vi ham IF %d\n", n);


    //printf_s("%d\n", glo);
    //custom();
    //printf_s("%d\n", glo);
    //custom2();
    //for (int i = 0; i < 10; ++i) {
    //    if (i == 5) {
    //        break;
    //    }
    //    printf_s("%d", i); 
    //}
    return 0;
}