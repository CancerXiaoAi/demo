#include<stdio.h>
int main () {
	int num;
	printf("����1~7����: ");
	scanf("%d", &num);
	switch (num) {
		case 1:
			printf("����һ");
			break;
		case 2:
			printf("���ڶ�");
			break;
		case 3:
			printf("������");
			break;
		case 4:
			printf("������");
			break;
		case 5:
			printf("������");
			break;
		case 6:
			printf("������");
			break;
		case 7:
			printf("������");
			break;
		default:
			printf("��������ֲ��Ϸ�");
	}
}