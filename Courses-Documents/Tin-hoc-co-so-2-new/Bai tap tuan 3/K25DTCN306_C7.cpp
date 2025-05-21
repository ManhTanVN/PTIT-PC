#include <stdio.h>
#include <string.h>

int main() {
    char str1[21] = "Hello ";
    char str2[21] = { 'W', 'o', 'r', 'l', 'd', '\0' };
    char* ptr;

    printf("Hai chuoi truoc khi goi ham la:\n");
    printf("\tstr1: \"%s\"\n", str1);
    printf("\tstr2: \"%s\"\n", str2);

    // ham noi chuoi str2 vao chuoi str1
    ptr = strcat(str1, str2);

    printf("\nHai chuoi sau khi goi ham la:\n");
    printf("\tstr1: \"%s\"\n", str1);
    printf("\tstr2: \"%s\"\n", str2);

    printf("\nptr=%p, str1=%p\n", (void*)ptr, (void*)str1);

    fflush(stdin);
    getchar();
    return 0;
}
