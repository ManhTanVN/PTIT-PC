#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char msv[100];
	char hoten[100];
	double gpa;
	struct node *next;
};

typedef struct node node;

node* makeNode() {
	node *newNode = (node*)malloc(sizeof(node));
	getchar();
	printf("Mssv:\n");
	gets(newNode->msv);
	printf("Ho va ten:\n");
	gets(newNode->hoten);
	printf("GPA:\n");
	scanf("%lf", &(newNode->gpa));
	newNode->next = NULL;
	return newNode;
}
void pushFront(node **head) {
	node *newNode = makeNode();
	newNode->next = (*head);
	(*head) = newNode;
}
void pushBack(node **head) {
	node *newNode = makeNode();
	if(*head == NULL) {
		*head = newNode; return;
	}
	node *temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}
void insert(node **head, int k) {
	node *temp = *head;
	if (k == 1) {
		pushFront(&temp); return;
	}
	node *newNode = makeNode();
	if (*head == NULL) return;
	for (int i = 1; i < k; i ++) {
		if (i == (k-1)) {
			newNode->next = temp->next;
			temp->next = newNode;
			return;	
		}
		temp = temp->next;
	}
}
int size(node *head) {
	int cnt = 0;
	if (head != NULL){
		cnt++;
		while (head->next != NULL) {
			head = head->next;
			cnt++;
		}
	} 
	return cnt;
}
void duyetNode(node *head) {
	while (head != NULL) {
		printf("MSSV: %8s\nHo va Ten: %s\nGPA: %10.2lf\n", head->msv, head->hoten, head->gpa);
		head = head->next;
	}
}
int main() {
	node *head = NULL;
	while(1) {
		printf("-----------------------------------------------------------------\n");
		printf("1. Duyet sinh vien\n");
		printf("2. Them sinh vien vao dau ds\n");
		printf("3. Them sinh vien vao cuoi ds\n");
		printf("4. Chen sinh vien vao ds\n");
		printf("5. So luong sv trong ds\n");
		printf("0. Ket thuc\n");
		printf("-----------------------------------------------------------------\n");
		printf("Nhap lua chon\n");
		int lc;
		scanf("%d", &lc);
		if (lc == 1) {
			duyetNode(head);
		}
		if (lc == 2) {
			pushFront(&head);
		} 
		if (lc == 3) {
			pushBack(&head);
		}
		if (lc == 4) {
			int k;
			scanf("%d", &k);
			insert(&head, k);
		}
		if (lc == 5) {
			printf("%d\n", size(head));
		}
		if (lc == 0) {
			break;
		}
	}
	return 0;
}
