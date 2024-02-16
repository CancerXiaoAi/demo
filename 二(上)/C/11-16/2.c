#include <stdio.h>
int main () {
	int m;
	printf("输入月份: ");
	scanf("%d", &m);
	switch (m) {
		case 1:
			printf("总共有31天");
			break;
		case 2:
			printf("总共有28天");
			break;
		case 3:
			printf("总共有31天");
			break;
		case 4:
			printf("总共有30天");
			break;
		case 5:
			printf("总共有31天");
			break;
		case 6:
			printf("总共有30天");
			break;
		case 7:
			printf("总共有31天");
			break;
		case 8:
			printf("总共有31天");
			break;
		case 9:
			printf("总共有30天");
			break;
		case 10:
			printf("总共有31天");
			break;
		case 11:
			printf("总共有30天");
			break;
		case 12:
			printf("总共有31天");
			break;
		default:
			printf("输入的月份不合法");
			break;
	}
}