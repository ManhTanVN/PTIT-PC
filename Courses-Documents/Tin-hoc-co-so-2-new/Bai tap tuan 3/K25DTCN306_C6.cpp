#include <stdio.h>

int main() {
    char str[21];

    printf("Nhap vao mot chuoi: ");
    // Nen su dung nhap chuoi voi ham gets()
    gets(str);

    printf("Ban vua nhap vao chuoi: ");
    puts(str);

    fflush(stdin);  
    getchar();     
    return 0;
}
