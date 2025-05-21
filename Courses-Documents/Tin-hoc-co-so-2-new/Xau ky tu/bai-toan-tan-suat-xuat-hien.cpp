/*
bai tap ve tan suat xuat hien
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1. Dem tan so xuat hien
// 2. Tim ky tu xuat hien nhieu nhat -  it nhat
// 3. Ki tu chung cua 2 xau - ki tu chi xuat hien o 1 xau
void kituchung(char a[], char b[]){
	for (int i = 0; i < strlen(a); i++) {
		for (int j = 0; j < strlen(b); j++) {
			if (a[i] == b[j]) {
				printf("%c",a[i]);
			}
		}
	}
}
int main(){
	// 1. Dem tan so xuat hien
	char c[1000];
	gets(c);
	int cnt[256] = {0};
	char cnt2[256] = {0};
	for (int i = 0; i < strlen(c); i++) {
		cnt[c[i]]++;
		cnt2[c[i]]++;
	}
	for (int i = 0; i < strlen(c); i++){
		if(c[i] == ' ')
			cnt[c[i]] = 0;
		if (cnt[c[i]] != 0) {
			printf("so lan xuat hien cua %c la: %d\n",c[i], cnt[c[i]]);
			cnt[c[i]] = 0;
		}
	}
	// 2. Tim ky tu xuat hien nhieu nhat -  it nhat
	int cntmax = -1000000, cntmin = 1000000;
	int max,min = -1;
	for (int i = 0; i < strlen(c); i++){
		if (c[i] != ' ') {
			if (cnt2[c[i]] > cntmax) {
				cntmax = cnt2[c[i]];
				max = i;
			}
			if (cnt2[c[i]] < cntmin) {
				cntmin = cnt2[c[i]];
				min = i;
			}
		}
	}
	printf("ky tu xuat hien nhieu nhat la: %c\n", c[max]);
	printf("ky tu xuat hien it nhat la: %c\n", c[min]);
	
	// 3. Ki tu chung cua 2 xau - ki tu chi xuat hien o 1 xau
	char xau1[1000], xau2[1000];
	printf("Nhap xau1: \n");
	
	gets(xau1);
	
	printf("Nhap xau2: \n");
	
	gets(xau2);
	kituchung(xau1, xau2);
	
	
	return 0;
}
