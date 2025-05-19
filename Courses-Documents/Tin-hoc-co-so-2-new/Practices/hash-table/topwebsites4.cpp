#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define HASH_SIZE 2069 // Cho size bang hang so nguyen to 2069

// Khai báo hàm hash function
int hash_function(char *key) {
    unsigned long hash_size = 5831;
    int c;
    while((c = *key++)) {
        hash_size = ((hash_size<<5) + hash_size) + c; // hash_size * 33 + c
    }
    return hash_size % HASH_SIZE;
}

// Khai bao kieu du lieu thong tin can luu
typedef struct Node {
    char *name;
    int count;
    Node *next;
} Node;

// Khai báo mảng động chưa Node thông tin
typedef struct {
    Node *buckets[HASH_SIZE];
} HashTable;

// Hàm tạo hash table
HashTable *create_table() {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

// Thêm - sửa thông tin trong table
void update_table(HashTable *table, char *value) {
    int index = hash_function(value);

    // Kiểm tra value đã tồn tại hay không để sửa thông tin
    Node *current = table->buckets[index];
    if (current) {
        while (current) {
            if (strcmp(current->name, value) == 0) {
                current->count++;
                return;
            }
            current = current->next;
        }
    }
    // Thêm thông tin website vào table
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->name = (char*)malloc((strlen(value) + 1)*sizeof(char));
    strcpy(new_node->name, new_website);
    new_node->count = 1;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

// Duyệt table va đưa thông tin website vào mảng
int collect_websites(HashTable *table, Node **arr) {
    int count = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *current = table->buckets[i];
        while (current) {
            arr[count]->name = current->name;
            arr[count++]->count = current->count;
            current = current->next;
        }
    }
    return count;
}

// Giải phóng bộ nhớ
void free_table (HashTable *table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *current = table->buckets[i];
        while (current) {
            Node *tmp = current;
            current = current->next;
            free(tmp->name);
            free(tmp);
        }
    }
}

// Hàm so sánh
int cmp(const void *a, const void *b) {
    Node *wa = *(Node**)a;
    Node *wb = *(Node**)b;

    if (wa->count != wb->count) 
        return wb->count - wa->count;
    return strcmp(wa->name, wb->name);
}

int main () {
    FILE *f = fopen("log.txt", "r");
    if(!f) {
        printf("Can not find the input file!\n");
        return 1;
    }
    FILE *f2 = fopen("ketqua.txt", "w");
    if(!f2) {
        printf("Can not create an output file!\n");
        fclose(f);
        return 1;
    }

    HashTable *table = create_table();
    char line[1024];

    while (fgets(line, sizeof(line), f)) {
        char *token = strtok(line, " ");
        int idx = 0;
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (idx == 2) {
                break;
            }
            idx++;
        }

        if (token) {
            token[strcspn(token,"\n")] = '\0';
            update_table(table, token);
        }
    }

    Node *array[1000];
    int count = collect_websites(table, array);

    qsort(array, count, sizeof(Node*), cmp);

    for (int i = 0; i < count; i++) {
        fprintf(f2, "%s %d\n", array[i]->name, array[i]->count);
    }

    free_table(table);

    fclose(f);
    fclose(f2);

    return 0;

}