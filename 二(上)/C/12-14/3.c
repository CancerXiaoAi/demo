#include <string.h>
#include <stdio.h>

int main() {
	char passwords1[50];
	char passwords2[50];
	printf("���������룺");
	scanf("%s", passwords1);
	printf("���ٴ��������룺");
	scanf("%s", passwords2);
	if (strcmp(passwords1, passwords2) == 0) {
		printf("��������ɹ���\n");
	} else {
		printf("�������벻һ�£�\n");
	}
}
