#include <stdio.h>
int a = 1, b = 5; // Khai bao bien toan cuc, no se duoc dung o bat ky dau ke tu dong nay
int main() {
	// Khai bao 2 bien trong ham main, no se duoc dung trong tian bo ham main ke tu dong nay
	int c = 4, d = 6;
	if (c < d) {
		int e = 6, d = 8; // khai bao bien e v d, no duoc dung trong doan nay.
		c = 7;
		printf("gia tr cac bien trong khoi: \n");
		printf("e = %d \t d = %d \t c = %d\n", e, d, c);
	}
	
	printf("gia tro cac bien trong ham main: \n");
	printf("c = %d \t d = %d\n", c, d);
	printf("gia tri cac bien toan cuc:\n");
	printf("a = %d \t b = %d\n", a, b);
	return 0;
}
