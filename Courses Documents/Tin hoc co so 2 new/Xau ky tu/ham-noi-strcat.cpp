/*
ham noi xau dich vao xau nguon
char *res = strcat(char target[], char source[]); == [...target,...source]
*/

#include <stdio.h>
#include <string.h>

int main(){
	char target[] = "Happy new year ", source[] = "2025";
	//char *res = strcat(target, source);
	strcat(target, source);
	char res[1000];
	strcpy(res,target);
	printf("%s\n", res);
	printf("%s\n", target);
	printf("%s\n", source);
	return 0;
}
