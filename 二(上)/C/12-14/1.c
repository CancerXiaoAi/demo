#include <string.h>
#include <stdio.h>

int main() {
	char string[10];
	printf("������һ���ַ�����");
	scanf("%s", string);
	printf("������ַ���Ϊ��%s\n", string);
	printf("�ַ����ĳ���Ϊ��%d\n", strlen(string));
}
