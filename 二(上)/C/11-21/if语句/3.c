#include<stdio.h>
int main () {
	float t;
	char test;
	printf("����������ºͺ�����: (pΪ����,nΪ����): ");
	scanf("%f,%c", &t, &test);
	if (t < 37.3 && test == 'n') {
		printf("���Խ���\n");
	}
	if (t >= 37.3 && test == 'n') {
		printf("�Ӽ�\n");
	}
	if (t >= 37.3 && test == 'p') {
		printf("��������\n");
	}
	if (t < 37.3 && test == 'p') {
		printf("��������\n");
	}
}