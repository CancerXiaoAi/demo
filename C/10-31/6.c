#include <stdio.h>
main(){
	char ch;
	printf("������һ���ַ�: ");
	scanf("%c", &ch);
	if(ch >= 'a' && ch <= 'z')
		printf("%c", ch);
	else
		printf("����Ĳ���Сд��ĸ\n");
}