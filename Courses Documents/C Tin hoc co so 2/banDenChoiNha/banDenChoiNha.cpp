#include <stdio.h>
#include <math.h>

int main() {
	// Tim khoang cach nho nhat
	//int d1, d2, d3;
	//scanf_s("%d %d %d", &d1, &d2, &d3);
	//int kc1 = d1 + d2 + d3;
	//int kc2 = 2*(d1 + d2);
	//int kc3 = 2*(d2 + d3);
	//int kc4 = 2*(d1 + d3);
	//printf_s("%d %d %d %d \n", kc1, kc2, kc3, kc4);
	//int res = fmin(fmin(kc1, kc2), fmin(kc3, kc4));
	//printf_s("Khoang cach ngan nhat la %d", res);


	/*Bai toan doi tien*/
	int tongtien;
	scanf_s("%d", &tongtien);
	// menh gia tien la 1, 5, 10, 20, 100
	int sototien = 0;
	sototien += tongtien / 100; 
	tongtien %= 100;
	sototien += tongtien / 20; 
	tongtien %= 20;
	sototien += tongtien / 10; 
	tongtien %= 10;
	sototien += tongtien / 5; 
	tongtien %= 5;
	sototien += tongtien;

	printf_s("tong so to tien nhan ve la %d", sototien);


	return 0;
}