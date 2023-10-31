#include <stdio.h>
main(){
	char ch;
	printf("请输入一个字符: ");
	scanf("%c", &ch);
	if(ch >= 'A' && ch <= 'Z')
		printf("%c", ch);
	else
		printf("输入的不是大写字母\n");
}