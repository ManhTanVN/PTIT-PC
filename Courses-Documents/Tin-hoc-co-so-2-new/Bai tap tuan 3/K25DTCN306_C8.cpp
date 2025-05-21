#include <stdio.h>
#include <string.h>
main()
{
    char str[21], ch, * pos;
    printf("Nhap vao mot chuoi: ");
    gets(str);
    printf("Nhap mot ky tu: ");
    scanf("%c", &ch);

    //ham tim kiem ky tu ch trong chuoi str
    pos = strchr(str, ch);

    if (pos == NULL)
        printf("Khong co ky tu '%c' trong chuoi \"%s\"", ch, str);
    else
        printf("Ky tu '%c' nam trong chuoi \"%s\" o vi tri thu %d", ch, str, pos - str);
    fflush(stdin);
    getchar();
}