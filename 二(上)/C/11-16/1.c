#include <stdio.h>
int main () {
	int num;
	printf("����¥����: ");
	scanf("%d", &num);
	switch (num) {
		case 1:
			printf("��ӭ����1¥\n");
			break;
		case 2:
			printf("��ӭ����2¥\n");
			break; 
		case 3:
			printf("��ӭ����3¥\n");
			break; 
		case 4:
			printf("��ӭ����4¥\n");
			break; 
		case 5:
			printf("��ӭ����5¥\n");
			break; 
		default :
			printf("�����¥�������Ϸ�");
	}
}