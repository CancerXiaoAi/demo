#include <stdio.h>
int main () {
	int num;
	printf("输入楼层数: ");
	scanf("%d", &num);
	switch (num) {
		case 1:
			printf("欢迎来到1楼\n");
			break;
		case 2:
			printf("欢迎来到2楼\n");
			break; 
		case 3:
			printf("欢迎来到3楼\n");
			break; 
		case 4:
			printf("欢迎来到4楼\n");
			break; 
		case 5:
			printf("欢迎来到5楼\n");
			break; 
		default :
			printf("输入的楼层数不合法");
	}
}