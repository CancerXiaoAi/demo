#include <stdio.h>
int main () {
	char c;
	printf("����һ���ַ�: ");
	scanf("%c", &c);
	if(c >= 97 && c <= 122 || c >= 65 && c <= 90) {
		printf("���������ĸ\n");
	}
	if (c >= 48 && c <= 57) {
		printf("�����������\n");
	}
	if (c == ' ') {
		printf("������ǿո�\n");
	}
}