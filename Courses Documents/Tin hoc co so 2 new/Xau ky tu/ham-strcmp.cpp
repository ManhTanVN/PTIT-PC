/*
ham int cp strcpm(char a[], char b[]); so sanh chuoi
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	char a[] = "happy new year a", b[]= "happy new year b";
	int cp = strcmp(a,b);
	printf("%d\t", cp);
	printf("compare: %d\n", strcmp(a,b));
	return 0;
}
