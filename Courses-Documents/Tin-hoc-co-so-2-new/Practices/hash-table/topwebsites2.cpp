#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 101 // Số nguyên tố để giảm xung đột

// Hàm băm hash
int hash_function(const char* key, int size) {
    unsigned long hash = 5381;
    int c;
    while((c = *key++)) {
         hash =  ((hash<<5) + hash) + c; // hash * 33 + c
    }
    return hash % size; // trả vè số trong khoảng 0 - size - 1;
}

// Cấu trúc website sử dụng bảng băm
typedef struct Node {
    char *name;        // Tên website (key)
    int count;         // Số lần truy cập (value)
    struct Node *next;  // Xử lý bảng băm
} Node;

// Cấu trúc hash-table
typedef struct HashTable {
    Node *buckets[HASH_SIZE];
} HashTable;

// Hàm tạo bảng băm
HashTable* create_table() {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

// Thêm hoặc cập nhật thông tin website
void add_website(HashTable *table, const char *name) {
    int index = hash_function(name, HASH_SIZE);
    Node* current = table->buckets[index];

    // Update count nếu tén website đã tồn tại
    while (current != NULL)
    {
        if (strcmp(current->name,name) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    
    // Thêm mới vào đầu danh sách liên kết
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->name = (char*)malloc(strlen(name) + 1);
    strcpy(new_node->name, name);

    new_node->count = 1;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

// Duyệt và lưu kết quả ra mảng
int collect_websites(HashTable *table, Node **array) {
    int count = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *current = table->buckets[i];
        while (current) {
            array[count++] = current;
            current = current->next;
        }
    }
    return count;
}

// Giải phóng bộ nhớ
void free_table(HashTable* table) {
    for(int i = 0; i < HASH_SIZE; i++) {
        Node *current = table->buckets[i];
        while(current) {
            Node *tmp = current;
            current = current->next;
            free(tmp->name);
            free(tmp);
        }
    }
    free(table);
}

// Hàm so sánh
int cmp(const void *a, const void *b) {
    Node*wa  = *(Node**)a;
    Node*wb  = *(Node**)b;
    if (wa->count != wb->count) 
        return wb->count - wa->count; // Giảm dần theo lượt truy cập
    return strcmp(wa->name,wb->name); // Tăng dần theo từ điển
}


int main() {
    FILE *f1 = fopen("d:/PTIT2/Courses-Documents/Tin-hoc-co-so-2-new/Practices/hash-table/log.txt", "r");  // Đường dẫn tuyệt đối

    if(!f1) {
        printf("Can not find input files! \n");
        return 1;
    }
    FILE *f2 = fopen("topWebsites.txt", "w");
    if(!f2) {
        printf("Can not find output files! \n");
        fclose(f1);
        return 1;
    }

    HashTable *table = create_table();
    char line[1024];
    // Duyệt qua từng dòng của file input
    while (fgets(line, 1024, f1)) {
        if (line[0] == '\n' || isspace(line[0])) continue; //bỏ qua dòng không hợp lệ

        char* token = strtok(line, " ");
        if (token) token = strtok(NULL, " ");
        if (token) token = strtok(NULL, " ");

        // thêm tên website vào table
        if (token) add_website(table, token);
    }

    // In thông tin website ra mảng
    Node *array[1000];
    int count = collect_websites(table, array);

    // Sort array
    qsort(array, count, sizeof(Node*), cmp);

    // In kết quả ra file output
    for (int i = 0; i < count; i ++) {
        fprintf(f2, "%s %d\n", array[i]->name, array[i]->count);
    }

    // Giải phóng table
    free_table(table);

    // Đóng files
    fclose(f1);
    fclose(f2);
    
    return 0;
}