/*
Bạn được cung cấp log truy cập trang web và dấu thời gian truy cập, nhiệm vụ của
bạn là tìm ra trang web có lượt truy cập nhiều nhất. File "log.txt" lưu các lượt truy
cập, bạn hãy ghi ra file "topweb.txt" các website kèm theo lượt truy cập tương ứng
các website được ghi theo thứ tự giảm dần về tần suất, nếu 2 websites có cùng lượt 
truy cập thi ghi file có thứ tự từ điển nhở hơn trước.
*/

#include <stdio.h>
char** topwebs(char line[300], int *n) {
    int capacity = 10;
    char** results = (char**)malloc(capacity * sizeof(char*));
    while(strtok(line, " ") != NULL) {
        
    }
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
    }
    int capacity = 10;
    char** info[capacity][2];
    return 0;
}