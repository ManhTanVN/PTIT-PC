#include <stdio.h>

#define AGE_MAX 150      // hang so
#define C 'a'            // hang ky tu
#define NICK_NAME "abc"  // hang chuoi

int main() {
    printf("hang AGE_MAX = %d\n", AGE_MAX);
    printf("hang C = %c\n", C);
    printf("hang NICK_NAME = %s\n", NICK_NAME);

    // AGE_MAX = 10; // Lenh nay sai vi hang khong the thay doi duoc gia tri
    return 0;
}

