#include <stdio.h>
main(){
	char ch;
	printf("������һ���ַ�: ");
	scanf("%c", &ch);
	if(ch >= 'A' && ch <= 'Z')
		printf("%c", ch);
}