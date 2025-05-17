#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpper(char c[]) {
	for (int i = 0; i < strlen(c); i++) {
		c[i] = toupper(c[i]);
	}
}

int main() {
	char c[100];
	gets(c);
	char *b = strlwr(c);
	char bb[1000];
	gets(bb);
	printf("%s\n", c);
	printf("%s\n", bb);
	printf("%s\n", c);
	return 0;
}
