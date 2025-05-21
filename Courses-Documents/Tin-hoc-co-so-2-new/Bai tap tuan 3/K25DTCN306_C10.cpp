#include <stdio.h>
#include <string.h>
main()
{
    char str[21];
    printf("Nhap vao mot chuoi: ");
    gets(str);
    printf("Ban vua nhap vao chuoi co %d ky tu", strlen(str));
    fflush(stdin);
    getchar();
}