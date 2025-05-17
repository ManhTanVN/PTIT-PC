#include <stdio.h>

int main() {
    printf("char size = %d byte\n", sizeof(char));
    printf("short size = %d byte\n", sizeof(short));
    printf("int size = %d byte\n", sizeof(int));
    printf("long size = %d byte\n", sizeof(long));
    printf("float size = %d byte\n", sizeof(float));
    printf("double size = %d byte\n", sizeof(double));
    printf("1.55 size = %d byte\n", sizeof(1.55));
    printf("\"Hello\" size = %d byte\n", sizeof("Hello"));
    return 0;
}

