// chuan-hoa-ten.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define Len 100
#define Words 10
// custom strdup
char* custom_strdup(const char* s) {
    char* newstr = (char*)malloc((strlen(s) + 1) * sizeof(char));
    if (newstr) {
        strcpy(newstr, s);
    }
    return newstr;
}

// Chuan hoa ten
void name_corrector(char* s) {
    int i = 0, j = 0;
    // Xoa khoang trang dau neu co
    while (s[i] == ' ') i++;

    int space = 0;
    while (s[i]) {
        if (s[i] != ' ') {
            if (j == 0 || space) {
                // viet hoa ky tu dau tien
                s[j++] = toupper(s[i]);
            }
            else {
                // viet thuong cac ky tu tiep theo
                s[j++] = tolower(s[i]);
            }
            space = 0;
        }
        else if (!space) {
            s[j++] = ' ';
            space = 1;
        }
        i++;
    }

    // Xoa khoang trang cuoi neu co
    if (j > 0 && s[j - 1] == ' ') j--;
    s[j] = '\0';

}

// Ham so sanh sap xep
int cmp(const void* a, const void* b) {
    char* aname = *(char**)a;
    char* bname = *(char**)b;

    char* worda[Words], * wordb[Words];
    int counta = 0, countb = 0;

    char* tempa = custom_strdup(aname);
    char* tempb = custom_strdup(bname);
    if (!tempa || !tempb) return 0;

    char* tokena = strtok(tempa, " ");
    while (tokena) {
        worda[counta++] = custom_strdup(tokena);
        tokena = strtok(NULL, " ");
    }
    char* tokenb = strtok(tempb, " ");
    while (tokenb) {
        wordb[countb++] = custom_strdup(tokenb);
        tokenb = strtok(NULL, " ");
    }

    // So sanh theo Ten -> Dem -> Ho
    int result = strcmp(worda[counta - 1], wordb[countb - 1]); // Ten
    if (result == 0) {
        for (int i = 1; i < counta - 1 && i < countb - 1; i++) { // Dem
            result = strcmp(worda[i], wordb[i]);
            if (result != 0) break;
        }
        if (result == 0) {
            result = strcmp(worda[0], wordb[0]); // Ho
        }
    }

    for (int i = 0; i < counta; i++) free(worda[i]);
    for (int i = 0; i < countb; i++) free(wordb[i]);
    free(tempa);
    free(tempb);
    return result;
}

int main()
{
    FILE* f = fopen("name.txt", "r");
    if (!f) {
        printf("Can not find the input file!\n");
        return 1;
    }
    FILE* f2 = fopen("convert.txt", "w");
    if (!f2) {
        printf("Can not create the output file!\n");
        fclose(f);
        return 1;
    }
    char* arr[1000];
    char line[1024];
    int n = 0;
    while (fgets(line, sizeof(line), f)) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
        name_corrector(line);
        arr[n++] = custom_strdup(line);
    }

    qsort(arr, n, sizeof(char*), cmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        fprintf(f2, "%s\n", arr[i]);
        free(arr[i]);
    }
    fclose(f);
    fclose(f2);
    return 0;
}