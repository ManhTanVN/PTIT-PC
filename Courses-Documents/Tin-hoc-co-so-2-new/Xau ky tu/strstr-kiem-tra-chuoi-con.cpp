/*
ham kiem tra co chua xau khac
ham tra ve con tro == NULL or dia chi
strstr(char target[], char source[]); == includes or indexOf 
*/

#include <stdio.h>
#include <string.h>

int main(){
	char target[] = "Happy new year ", source[] = "year";
	//char *res = strcat(target, source);
	char *ptr = strstr(target, source);

	if (ptr) 
		printf("chua chuoi con\n");
	else 
		printf("khong chua chuoi con\n");
	return 0;
}
