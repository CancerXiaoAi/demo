#include <stdio.h>
main(){
	char a, b;
	printf("�����һ���ַ�: ");
	scanf("%c", &a);fflush(stdin);
	printf("����ڶ����ַ�: ");
	scanf("%c", &b);fflush(stdin);
	printf("��һ���ַ���: %c\n", a);
	printf("�ڶ����ַ���: %c\n", b);
}