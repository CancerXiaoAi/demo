#include <string.h>
#include <stdio.h>

int main() {
	char str1[10];
	char str2[10];
	char result[20];
	printf("�������һ���ַ�����");
	scanf("%s", str1);
	printf("������ڶ����ַ�����");
	scanf("%s", str2);
	printf("��һ���ַ���Ϊ��%s\n", str1);
	printf("�ڶ����ַ���Ϊ��%s\n", str2);
	strcpy(result, str1);
	strcat(result, str2);
	printf("���Ӻ���ַ���Ϊ��%s\n", result);
}
