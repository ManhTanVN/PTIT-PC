#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Ham strtok

int main() {
	char c[1000];
	gets(c);
	char* word = strtok(c," ");
	while(word != NULL) {
		printf("%s\n", word);
		word = strtok(NULL, " ");
	}
	
	char cc[1000];
	gets(cc);
	char a[100][100];
	char *word2 = strtok(cc, " ");
	int n = 0;
	while (word2 != NULL) {
		strcpy(a[n], word2);
		n++;
		word2 = strtok(NULL, " ");
	}
	printf("%d\n", n);
	for (int i = 0 ; i < n; i ++) {
		printf("%s\n", a[i]);
	}
}
