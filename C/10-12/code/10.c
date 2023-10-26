#include <stdio.h>
main(){
	char a, b;
	printf("输入第一个字符: ");
	scanf("%c", &a);fflush(stdin);
	printf("输入第二个字符: ");
	scanf("%c", &b);fflush(stdin);
	printf("第一个字符是: %c\n", a);
	printf("第二个字符是: %c\n", b);
}