// Cac ham trong xu ly xau
/*

=>> need to include ctype.h library

isdigit(char c)
islower(char c)
isupper(char c)
isalpha(char c) >< isdigit
int tolower(char c)
int toupper(char c)
char *chuoi2c = strupr(chuoi2);

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char c[] = "helloWorld@2025";
	int lower = 0, upper = 0, digit = 0;
	for (int i = 0; i < strlen(c); i++) {
		if(islower(c[i])){
			lower++;
		}
		if(isupper(c[i])){
			upper++;
		}
		if(isdigit(c[i])){
			digit++;
		}
	}
	printf("%d %d %d\n", lower, upper, digit);
	
	// tolower vs toupper
	
	char low = 'c', upp = 'C';
	int thuong = tolower(upp);
	int hoa = toupper(low);
	
	printf("thuong sang hoa: %c - %c\n", low, hoa);
	printf("hoa sang thuong: %c - %c\n", upp, thuong);
	
	// strlwr = string lower 
	// strupr
	
	char chuoi2[] = "Happy New Year @2025";
	char *chuoi2b = strlwr(chuoi2);
	printf("strlwr: %s - %s\n", chuoi2, chuoi2b);
	char *chuoi2c = strupr(chuoi2);
	printf("struppr: %s - %s\n", chuoi2, chuoi2b);
	
	
	
	
	return 0;
	
}

