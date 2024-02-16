#include <stdio.h>
int main () {
	int m;
	printf("输入成绩: ");
	scanf("%d", &m);
	m /= 10;
	switch (m) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			printf("等级为E: ");
			break;
		case 6:
			printf("等级为D: ");
			break;
		case 7:
			printf("等级为C: ");
			break;
		case 8:
			printf("等级为B: ");
			break;
		case 9:
			printf("等级为A: ");
			break;
		default:
			printf("输入的成绩不合法");
			break;
	}
}