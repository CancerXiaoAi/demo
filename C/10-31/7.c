#include <stdio.h>
main(){
	char ch;
	printf("ÇëÊäÈëÒ»¸ö×Ö·û: ");
	scanf("%c", &ch);
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		printf("%c", ch);
}