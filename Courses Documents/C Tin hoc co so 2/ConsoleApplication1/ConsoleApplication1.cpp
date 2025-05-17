#include <stdio.h>
#include <math.h>

int main()
{
	/*Bai toan doi tien*/
	//int tongtien;
	//printf_s("Moi nhap vao so tien ban co trong ngan hang: \n");
	//scanf_s("%d", &tongtien);
	//// menh gia tien la 1, 5, 10, 20, 100
	//int sototien = 0;
	//sototien += tongtien / 100;
	//tongtien %= 100;
	//sototien += tongtien / 20;
	//tongtien %= 20;
	//sototien += tongtien / 10;
	//tongtien %= 10;
	//sototien += tongtien / 5;
	//tongtien %= 5;
	//sototien += tongtien;

	//printf_s("tong so to tien nhan ve la %d", sototien);

	// Bai toan tim so lon nhat va so nho nhat
	/*int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);

	int solonnhat = fmax(fmax(a, b), fmax(b, c));
	int sonhonhat = fmin(fmin(a, b), fmin(b, c));

	printf_s("so lon nhat la: %d \n", solonnhat);
	printf_s("so nho nhat la: %d", sonhonhat);*/

	//long long a, b, c, d;
	//scanf_s("%lld %lld %lld %lld", &a, &b, &c, &d);

	//long long min = a, max = b;
	//if (b < min) min = b;
	//if (c < min) min = c;
	//if (d < min) min = d;
	//if (a > max) max = a;
	//if (c > max) max = c;
	//if (d > max) max = d;

	//printf_s("so lon nhat la: %lld \n", max);
	//printf_s("so nho nhat la: %lld", min);

	// Lam tron so thuc
	/*float a;
	printf_s("Vui long nhap so thuc: \n");
	scanf_s("%f", &a);
	int soNguyenGanNhat = round(a);
	printf_s("so nguyen gan nhat la: %d", soNguyenGanNhat);*/

	// Cap so cong
	/*cho cap so cong co n phan tu, phan tu dau tien la u1, cong sai d. ting tong cua cap so cong*/
	//int n, u1, d;
	//printf_s("vui long nhap so luong phan tu, gia tri phan tu dau tien va cong sai cua cap so cong: \n");
	//scanf_s("%d %d %d", &n, &u1, &d);
	///*long long tong = 0;
	//for (int i = 0; i < n; i++) {
	//	tong += u1 + 1ll * i * d;
	//}*/
	//long long un = u1 + 1ll * (n - 1) * d;
	//long long tong = n * (un + u1) / 2;
	//long long check = 27 / 2;
	//printf_s("tong cua cap so cong la: %lld %lld", tong, check);

	// Cap so nhan
	/*Cho 4 so a b c d. Hay kiem tra xem 4 do nay co the theo thu tu tao thanh cap so nhan voi cong boi la so nguyen theo thu tu a b c d hay khong*/
	//int a, b, c, d;
	//printf_s("Vui long nhap vao 4 so a, b, c, d \n");
	//scanf_s("%d %d %d %d", &a, &b, &c, &d);
	//int congboi;
	//if (b % a == 0) {
	//	congboi = b / a;
	//	if (b * congboi == c && c * congboi == d) {
	//		printf_s("day so da cho tao thanh cap so nhan theo thu tu da cho voi cong boi la: %d", congboi);
	//	}
	//	else {
	//		printf_s("day so da cho khong tao thanh cap so nhan theo thu tu da cho!");
	//	}
	//}
	//else {
	//	printf_s("day so da cho khong tao thanh cap so nhan theo thu tu da cho!");
	//}


	/*Bai Toan To Hop
		Trong lop co n sinh vien va muon chon ra hai ban de tham gia cuoc thi khieu vu. Hoi co bao nhieu cach chon?*/
	
	//int n;
	//printf_s("Vui long nhap so luong sinh vien \n");
	//scanf_s("%d", &n);
	//long long tohop = 0;
	///*for (int i = 1; i < n; i++) {
	//	tohop += n - i;
	//}*/

	//tohop += 1ll * n * (1ll * n - 1) / 2;
	//printf_s("So to hop la: %lld", tohop);

//Bizon the Champion
//Bizon the Champion duoc goi la Champio voi ly do sau day.Bizon the Champion gan day nhận dc mot mon qua - mot tu kinh moi voi n kệ và anh quyet dinh đặt tất cả 
//danh hiệu của mình ở đó.Tất cả các món quà có thể được chia thành hai loại: huy chương và cúp.Bizon có a1 cúp giải nhất, a2 cúp giải nhì và a3 cúp giải ba.
//Bên cạnh đó anh có b1 huy chương giải nhất, b2 huy chương giải nhì, b3 huy chương giải ba.Đương nhiên, phần thưởng trong tủ phải sắp xếp cho thật đẹp, đó la lý
//do Bizon quyết định tuân theo nguyên tắc : Bất kỳ kệ nào cũng không thể chứa cả cúp và huy chương cùng một lúc; không có kệ nào có thể chứa nhiều hơn 5 cúp; không
//có kệ nào có thể chứa hơn 10 huy chương. Giúp Bizon tìm hiểu xem chúng tôi có thể đặt tất cả các phần thưởng để tất cả các điều kiện được đáp ứng hay không.

	/*int n, a1, a2, a3, b1, b2, b3;
	printf_s("Moi nhap so ke, cup va huy chuong! \n");
	scanf_s("%d %d %d %d %d %d %d", &n, &a1, &a2, &a3, &b1, &b2, &b3);

	int tongcup = a1 + a2 + a3;
	int tongHuyChuong = b1 + b2 + b3;

	int keCup, keHuyChuong;
	if (tongcup / 5 == 0) {
		keCup = tongcup / 5;
	}
	else {
		keCup = tongcup / 5 + 1;
	}
	if (tongHuyChuong / 10 == 0) {
		keHuyChuong = tongHuyChuong / 10;
	}
	else {
		keHuyChuong = tongHuyChuong / 10 + 1;
	}

	if (keCup + keHuyChuong <= n) {
		printf_s("YES");
	}
	else {
		printf_s("No");
	}*/


	//Ghep so
	
	//int k2, k3, k5, k6;
	//int y1 = 32, y2 = 256;
	//printf_s("Moi Nhap k2, k3, k5, k6! \n");
	//scanf_s("%d %d %d %d", &k2, &k3, &k5, &k6);

	//int min256 = fmin(fmin(k2, k5), k6);
	//int min32 = fmin(k3, (k2 - min256));

	//long long tong = 1ll * min256 * 256 + 1ll * min32 * 32;

	//printf_s("tong lon nhat la: %d", tong);


	// Chia tien
	//int a, b, c, n;
	//printf_s("Moi nhap so luong xu cua tung nguoi: \n");
	//scanf_s("%d %d %d %d", &a, &b, &c, &n);

	//int A, B, C;
	/*
		a + A + b + B = 2C + 2c;
		A + B + C = n;
		=>
		a + b + n - C = 2C + 2c;
		=> C = (a + b + n - 2c) / 3
		=> B = (a + c + n  - 2b) / 3
		=> A = (b + c + n  - 2a) / 3
	*/

	/*if ((a + b + n - 2 * c) % 3 == 0) {
		C = (a + b + n - 2 * c) / 3;
		B = (a + c + n - 2 * b) / 3;
		A = (b + c + n - 2 * a) / 3;

		printf_s("YES \n%d %d %d", A, B , C);
	}
	else {
		printf_s("NO \n");
	}*/
	//int tong = a + b + c + n;
	//if (tong % 3 == 0) {
	//	int res = tong % 3;
	//	if (res >= a && res >= b && res >= c) {
	//		printf_s("YES \n%d %d %d", res - a, res - b. res - c);
	//	}
	//	else {
	//		printf_s("NO \n");
	//	}
	//}
	//else {
	//	printf_s("NO \n");
	//}


	int h, m;
	printf_s("Hay nhap gio phu hien tai! \n");
	scanf_s("%d %d", &h, &m);

	int m_1 = h * 60 + m;

	int m_2 = 24 * 60;

	int m_3 = m_2 - m_1;

	int h2, m2;
	h2 = m_3 / 60;
	m2 = m_3 % 60;

	printf_s("Thoi gian con lai: %d gio %d phut \n", h2, m2);
	

	return 0;
}
