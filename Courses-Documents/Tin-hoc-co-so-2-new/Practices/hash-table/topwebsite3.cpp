#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define HASH_SIZE 2069

// Khai báo function băn
int hash_function (const char *key) {
    unsigned long hash = 5831;
    int c;
    while ((c = *key++)) {
        hash = ((hash<<5) + hash) + c;
    }
    return hash % HASH_SIZE;
}

// Khởi tạo kiểu dữ liệu thông tin cần lưu
typedef struct Node{
    char *name;
    int count;
    struct Node *next;
} Node;

// Khởi tạo kiểu dữ liệu là một mảng có độ dài HASH_SIZE kiểu dữ liệu thông tin website cần lưu
typedef struct {
    Node *buckets[HASH_SIZE];
} HashTable;

// Tạo  hash table
HashTable *create_table() {
    // Mảng 1 chiều có kiểu dữ liệu HashTable, độ dài  HASH_SIZE
    HashTable *table = (HashTable*)malloc(sizeof(HashTable)); 
    for (int i = 0; i < HASH_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}
// Thêm thông tin website
void add_website(HashTable *table, char *website) {
    int index = hash_function(website);
    Node *current = table->buckets[index];
    // tìm xem website đã tồn tại chưa thì tăng biến count;
    while (current != NULL) {
        if(strcmp(current->name, website) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    // Thêm website vào danh sách liên kết
    Node *new_website = (Node*)malloc(sizeof(Node));
    new_website->name = (char*)malloc((strlen(website) + 1) * sizeof(char));
    strcpy(new_website->name, website);
    new_website->count = 1;
    new_website->next = table->buckets[index];
    table->buckets[index] = new_website;
}

//Duyệt và lưu kết quả ra mảng
int collect_websites(HashTable *table, Node **res_array) {
    int count = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *current = table->buckets[i];
        while(current != NULL) {
            res_array[count++] = current;
            current = current->next;
        }
    }
    return count;
}

// Ham so sánh
int cmp(const void *a, const void *b) {
    Node *wa = *(Node**)a;
    Node *wb = *(Node**)b;

    if (wb->count != wa->count) 
        return wb->count - wa->count; // So sánh để lọc websites theo thứ tự tần suất truy cập giảm dần
    return strcmp(wa->name, wb->name);
}

// Hàm free table
void free_table(HashTable *table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *current = table->buckets[i];
        while (current != NULL) {
            Node *tmp = current;
            current = current->next;
            free(tmp->name);
            free(tmp);
        }
    }
    free(table);
}

int main() {
    FILE *f = fopen("log-1.txt", "r");
    if (!f) {
        printf("Can not find input file!");
        return 1;
    }
    FILE *f2 = fopen("results.txt", "w");
    if (!f2) {
        printf("Can not create output file!");
        fclose(f);
        return 1;
    }

    HashTable *table = create_table();
    char line[1024];
    // Lọc qua từng line và lấy tên website 
    while(fgets(line, sizeof(line), f)) {
        char *token = strtok(line, " ");
        int idx = 0;
        while (token != NULL) {
            idx++;
            if (idx == 3) break;
            token = strtok(NULL, " ");
        }

        if (token) {
            token[strcspn(token, "\n")] = '\0';
            add_website(table, token);
        }

    }

    // Xuất thông ra mảng
    Node *res_array[2069];
    int count = collect_websites(table, res_array);
    

    // Sort mảng theo yêu cầu bài toán
    qsort(res_array, count, sizeof(Node*), cmp);

    // Xuất thông tin ra file results
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", res_array[i]->name, res_array[i]->count);
        fprintf(f2, "%s %d\n", res_array[i]->name, res_array[i]->count);
    }

    // Giải phóng bộ nhớ
    free_table(table);

    // Đóng files
    fclose(f);
    fclose(f2);

    return 0;
}


