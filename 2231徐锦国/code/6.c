#include <stdio.h>
main(){
	char ch;
	printf("请输入一个字符: ");
	scanf("%c", &ch);
	if(ch >= 'a' && ch <= 'z')
		printf("%c", ch);
	else
		printf("输入的不是小写字母\n");
}