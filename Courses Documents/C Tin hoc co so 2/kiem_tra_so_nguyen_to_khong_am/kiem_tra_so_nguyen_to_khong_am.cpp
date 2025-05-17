// kiem_tra_so_nguyen_to_khong_am.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <math.h>

int soNguyenTo(int a) {
        if (a < 2) {
            return 0;
        }
        for (int i = 2; i <= sqrt(a); i++) {
            if (a % i == 0) {
                return 0;
            }
        }
        return 1;
   
}
int prime(int n) {
    if (n < 2) {
        return 0; // loại số âm, và 0, 1
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0; // kết thúc ngay tại đây
        }
    }
    return 1; // là số nguyên tố
}
int soSphenic(int n) {
    for (int i = 0; i <= sqrt(n); i++) {

    }
    return 1;
}
int main()
{
    printf_s("Hay nhap vao so ban muonk kiem tra\n");
    int a;
    scanf_s("%d", &a);
    printf_s(soNguyenTo(a) == 0 ? "so da cho khong la so nguyen to\n" : "so da cho la so nguyen to\n");
    printf_s(prime(a) == 0 ? "So da cho khong la so nguyen to: \n" : "So da cho la so nguyen to :\n");
    return 0;
}
