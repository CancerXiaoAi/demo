#include <stdio.h>
main(){
	char ch;
	printf("������һ���ַ�: ");
	scanf("%c", &ch);
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		printf("%c", ch);
	else
		printf("����Ĳ�����ĸ\n");
}