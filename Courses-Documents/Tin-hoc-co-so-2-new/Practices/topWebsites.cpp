/*
Bạn được cung cấp log truy cập trang web và dấu thời gian truy cập, nhiệm vụ của
bạn là tìm ra trang web có lượt truy cập nhiều nhất. File "log.txt" lưu các lượt truy
cập, bạn hãy ghi ra file "topweb.txt" các website kèm theo lượt truy cập tương ứng
các website được ghi theo thứ tự giảm dần về tần suất, nếu 2 websites có cùng lượt 
truy cập thi ghi file có thứ tự từ điển nhở hơn trước.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Website {
    char* name;
    int count;
} Wb;

int cmp(const void *a, const void *b) {
    Wb* wa = (Wb*)a;
    Wb* wb = (Wb*)b;
    if (wa->count != wb->count) 
        return wb->count - wa->count;
    return strcmp(wa->name, wb->name);
}

int main() {
    FILE *f = fopen("log.txt","r");
    if (!f) {
        printf("Can not find input file!\n");
        return 1;
    }
    FILE *f2 = fopen("topweb.txt","w");
    if (!f2) {
        printf("Can not open the output file! \n");
        fclose(f);
        return 1;
    }

    int capacity = 10;
    Wb* topwebsites = (Wb*)malloc(capacity * sizeof(Wb));
    if (!topwebsites) {
        printf("Memory allocation failed!\n");
        fclose(f);
        fclose(f2);
        return 1;
    }
    char line[1024];
    int count = 0;
    while(fgets(line, sizeof(line),f)) {
        if (line[0] == '\n' || isspace(line[0])) continue;
        int idx = 0;
        char* website = NULL;
        char* token = strtok(line, " ");
        while(token != NULL) {
            idx++;
            if (idx == 3) {
                website = token;
                break;
            }
            token = strtok(NULL, " ");
        }
        if (website) {
            // Remove '\n'
            website[strcspn(website, "\n")] = '\0';

            if (strlen(website) == 0) continue; // Bo qua dong khong hop le

            // Check if the website is existed in storage data
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(topwebsites[i].name, website) == 0) {
                    found = 1;
                    topwebsites[i].count++;
                    break;
                }
            }

            if (!found) {
                if (count >= capacity) {
                    capacity *= 2;
                    Wb* temp = (Wb*)realloc(topwebsites,capacity * sizeof(Wb));
                    if (!temp) {
                        printf("Memory allocation failed!\n");
                        for (int j = 0; j < count; j++) {
                            if (topwebsites[j].name) {
                                free(topwebsites[j].name);
                            }
                        }
                        free(topwebsites);
                        fclose(f);
                        fclose(f2);
                        return 1;
                    }
                    topwebsites = temp;
                }
                topwebsites[count].name = (char*)malloc((strlen(website) + 1) * sizeof(char));
                if (!topwebsites[count].name) {
                    printf("Memory allocation failed!\n");
                    for (int j = 0; j < count; j++) {
                        if (topwebsites[j].name) {
                            free(topwebsites[j].name);
                        }
                    }
                    free(topwebsites);
                    fclose(f);
                    fclose(f2);
                    return 1;
                }
                strcpy(topwebsites[count].name, website);
                topwebsites[count].count = 1;
                count++;
            }
        }
    }

    qsort(topwebsites, count, sizeof(Wb),cmp);

    for(int i = 0; i < count; i++) {
        fprintf(f2,"%s %d\n",topwebsites[i].name, topwebsites[i].count);
        printf("%s %d\n",topwebsites[i].name, topwebsites[i].count);
        free(topwebsites[i].name);
    }
    free(topwebsites);

    fclose(f);
    fclose(f2);
    return 0;
}