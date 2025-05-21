// find_first_item.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
int find_first(int a[], int n, int x) {
	int l = 0, r = n - 1, res = -1; 
	while (l <= r)
	{
		int mid = (r + l) / 2;
		if (a[mid] == x) {
			res = mid;
			r = mid - 1;
		}
		if (a[mid] > x) {
			r = mid - 1;
		}
		if (a[mid] < x) {
			l = mid + 1;
		}
	}
	return res;
}
int main()
{
	int n;
	printf_s("Do dai mang can tim!\n");
	scanf_s("%d", &n);
	int* a = new int[n];
	printf_s("Vui long nhap mang!\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	printf_s("Nhap so can tim: \n");
	int x;
	scanf_s("%d", &x);
	int index = find_first(a, n, x);
	if (index >= 0) {
		printf_s("Vi tri dau tien tim duoc la: %d\n", index);
	}
	else {
		printf_s("Khong tim thay\n");
	}
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
