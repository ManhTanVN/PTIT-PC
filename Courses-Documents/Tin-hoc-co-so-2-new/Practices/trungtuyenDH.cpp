#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct SV {
    char hoTen[100];
    char email[150];
    char sdt[11];
    float tongDiem;
};
typedef struct SV SV;

int cmp(const void *a, const void *b) {
    SV *sv1 = (SV*)a;
    SV *sv2 = (SV*)b;
    if (sv1 -> tongDiem > sv2 -> tongDiem) return -1;
    if (sv1 -> tongDiem < sv2 -> tongDiem) return 1;
    return 0;
}
int main(){
    FILE* f = fopen("DiemThi.txt", "r");
    if (!f) {
        printf("Can not find input file!\n");
        return 1;
    }
    FILE* f2 = fopen("TrungTuyen.txt", "w");
    if (!f2) {
        printf("Can not find output file!\n");
        fclose(f);
        return 1;
    }

    char line[1024];
    int idx = 0;
    SV sv[1000];
    while(fgets(line, sizeof(line), f)) {
        char hoTen[100], email[150], sdt[11];
        float t, l, h;
        // get hoTen and remove \n
        line[strcspn(line, "\n")] = '\0';
        strcpy(hoTen, line);
        
        // Email vs sdt
        if(fscanf(f, "%s %s", email, sdt) != 2) break;

        // Diem toan ly hoa
        if(fscanf(f, "%f %f %f", &t, &l, &h) != 3) break;
        fgetc(f); // Remove "\n"

        strcpy(sv[idx].hoTen, hoTen);
        strcpy(sv[idx].email, email);
        strcpy(sv[idx].sdt, sdt);
        sv[idx].tongDiem = t + l + h;
        idx++;
    }
    // Sap xep danh sach sinh vien giam dan theo tong diem
    qsort(sv,idx ,sizeof(SV), cmp);

    // In sinh vien trung tuyen
    for (int i = 0; i < idx; i++) {
        if (sv[i].tongDiem >= 21) {
            fprintf(f2,"%s\n%s\n%s\n%.2f\n",sv[i].hoTen, sv[i].email, sv[i].sdt, sv[i].tongDiem);
            printf("%s\n%s\n%s\n%.2f\n",sv[i].hoTen, sv[i].email, sv[i].sdt, sv[i].tongDiem);
        }
    }
    // Close files
    fclose(f);
    fclose(f2);
    return 0;
}