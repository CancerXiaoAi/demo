#include <stdio.h>
main(){
	char a;
	printf("输入一个字符: ");
	a = getchar();
	printf("你输入的字符是: ");
	putwchar(a);
	printf("\n");
}