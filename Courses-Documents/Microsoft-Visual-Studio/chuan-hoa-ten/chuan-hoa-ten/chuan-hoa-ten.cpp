// chuan-hoa-ten.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Size 1024

// Ham so sanh sap xep
int cmp(const void *a, const void *b) {
    char* aname = *(char**)a;
    char* bname = *(char**)b;
    int counta = 0, countb = 0;
    char *worda[10], *wordb[10];
    char* tokena = strtok(aname, " ");
    char* tokenb = strtok(bname, " ");
    while (tokena || tokenb) {
        if (tokena) {
            strcpy(worda[counta], tokena);
            counta++;
            tokena = strtok(NULL, " ");
        } 
        if (tokenb) {
            strcpy(wordb[countb], tokenb);
            countb++;
            tokenb = strtok(NULL, " ");
        }
    }
    while (1) {
        if (strcmp(worda[counta--], wordb[countb--]) != 0)
            return strcmp(worda[counta--], worda[counta--]);
        if (!worda[counta] || !wordb[countb])
            return 0;
    }
}

int main()
{
    char *arr[1000];

    strcpy(arr[1], "Nguyen van nam");
    strcpy(arr[2], "Nguyen van bac");
    strcpy(arr[3], "Pham thi dong");
    strcpy(arr[0], "Pham thi tay");

    qsort(arr, 4, sizeof(char*), cmp);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", arr[i]);
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
