// mang2chieu_loang.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mission: find all areas that belong to an area of 1 in 0,1; 
//

#include <stdio.h>

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int a[100][100];
int n, m;
void loang(int i, int j) {
    a[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == 1) {
            loang(i1, j1);
        }
    }

}
int count(int n, int m) {
    int dem = 0;
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                loang(i, j);
                dem++;
            }
        }
    }
    return dem;
}
int main()
{
    scanf_s("%d %d", &n, &m);
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }

    printf_s("total areas is %d\n", count(n,m));
    return 0;
}