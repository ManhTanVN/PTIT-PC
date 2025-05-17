#include <stdio.h>

int main() {
	int so1, so2;
    float thuong;
    char pheptoan;
    scanf("%f %f", &so1, &so2);
    fflush(stdin); // Xoa ky tu enter trong vung dem truoc khi nhap phep toan
    scanf("%c", &pheptoan);
    switch (pheptoan) {
        case '+':
            printf("\n %d + %d = %d", so1, so2, so1 + so2);
            break;
        case '-':
            printf("\n %d - %d = %d", so1, so2, so1 - so2);
            break;
        case '*':
            printf("\n %d * %d = %d", so1, so2, so1 * so2);
            break;
        case '/':
            if (so2 != 0) {
                thuong = so1 / so2;
                printf("\n %d / %d = %d", so1, so2, thuong);
            } else {
                printf("Khong the chia duoc cho 0");
            }
            break;
        default:
            printf("\n Chua ho tro phep toan %c", pheptoan);
    }
    return 0;
}
