#include <stdio.h>
int main () {
	int m;
	printf("����ɼ�: ");
	scanf("%d", &m);
	m /= 10;
	switch (m) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			printf("�ȼ�ΪE: ");
			break;
		case 6:
			printf("�ȼ�ΪD: ");
			break;
		case 7:
			printf("�ȼ�ΪC: ");
			break;
		case 8:
			printf("�ȼ�ΪB: ");
			break;
		case 9:
			printf("�ȼ�ΪA: ");
			break;
		default:
			printf("����ĳɼ����Ϸ�");
			break;
	}
}