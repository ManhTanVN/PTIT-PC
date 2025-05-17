// mang2chieu_duyetcac_o_lien_ke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dx2[8] = { -1,-1,-1,0,0,1,1,1 };
int dy2[8] = { -1,0,1,-1,1,-1,0,1 };

int main()
{
    int a[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int i = 1, j = 1;

    for (int k = 0; k < 4;k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        printf_s("%d ", a[i1][j1]);
    }
    printf_s("\n");
    for (int k = 0; k < 8;k++) {
        int i1 = i + dx2[k], j1 = j + dy2[k];
        printf_s("%d ", a[i1][j1]);
    }
    return 0;
}
