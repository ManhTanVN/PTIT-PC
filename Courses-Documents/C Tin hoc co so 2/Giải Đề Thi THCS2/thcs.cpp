#include <stdio.h>

int main() {
	/*long long n, S;
	scanf_s("%lld %lld", &n, &S);
	if (S % n == 0) {
		printf("%lld", S / n);
	}
	else {
		printf("%lld", S / n + 1);
	}*/
	// doremon leo cau thang
	int n, m;
	scanf_s("%d %d", &n, &m);
	printf("So buoc toi thieu la: \n");
	int min , max = n;
	if (n % 2 == 0)
		min = n / 2;
	else
		min = n / 2 + 1;
	int res = (min + m - 1) / m * m;
	if (res <= max)
		printf("%d", res);
	else
		printf("-1");

	return 0;
}