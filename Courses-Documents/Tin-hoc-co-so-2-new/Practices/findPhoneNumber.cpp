#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


char** findNumber2 (const char* c, int *count) {
	int len = strlen(c);
	int rows = 10, cols = 11;
	int capacity = 2;
	char** results = (char**)malloc(capacity * sizeof(char*));

	for (int i = 0; i <= len - 10; i++) {
		// check if the first number is 0;
		if (c[i] == '0' && (i == 0 || !isdigit((unsigned char)c[i - 1]))) {
			int isAllNumber = 1;
			// check if 9 following numbers are numbers
			if (!isdigit(c[i + 10])) {
				for (int j = 1; j < 10; j++) {
					if (!isdigit(c[i + j])) {
						isAllNumber = 0;
						break;
					}
				}
			} else {
				isAllNumber = 0;
			}
			if (isAllNumber) {
				if (*count >= capacity) {
					capacity += 1;
					results = (char**)realloc(results, capacity * sizeof(char**));
				}
				results[*count] = (char*)malloc(cols * sizeof(char));
				strncpy(results[*count], &c[i], 10);
				results[*count][cols] = '\0';
				(*count)++;
			}
		}
	}
	
	return *count > 0 ? results : NULL;
}

char* findPhoneNumber(const char* input) {
    int len = strlen(input);
    for (int i = 0; i <= len - 10; i++) {
        // Kiểm tra ký tự đầu tiên có phải là '0' không
        if (input[i] == '0') {
            int isAllDigits = 1;

            // Kiểm tra 9 ký tự tiếp theo có phải toàn số không
            for (int j = 1; j < 10; j++) {
                if (!isdigit(input[i + j])) {
                    isAllDigits = 0;
                    break;
                }
            }

            if (isAllDigits) {
                // Cấp phát bộ nhớ cho chuỗi kết quả
                char* result = (char*)malloc(11); // 9 ký tự + 1 ký tự null
                strncpy(result, &input[i], 10);
                result[10] = '\0'; // Kết thúc chuỗi
                return result;
            }
        }
    }

    return NULL; // Không tìm thấy
}

int main(){
    FILE* f = fopen("binhluan.txt","r");
	if (!f) {
		printf("Can not open file!\n");
		return 1;
	}
	FILE* f2 = fopen("SDT.txt", "w");
	if (!f2) {
		printf("Can not output file!\n");
		fclose(f2);
		fclose(f);
		return 1;
	}
	
	char line[1024];
	while(fgets(line, sizeof(line),f)) {
		int count = 0;
		char** res = findNumber2(line, &count);
		if (res) {
			for (int i = 0; i < count; i++) {
				fprintf(f2, "%s\n", res[i]);
				free(res[i]);
			}
			free(res);
		}
	}
	fclose(f2);
	fclose(f);
    return 0;
}