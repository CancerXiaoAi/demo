#include <stdio.h>
int main () {
	int num;
	printf("输入一个整数: ");
	scanf("%d", &num);
	if(num >= 0) {
		printf("输出为: %d\n", num);
	}else if(num < 0) {
			printf("输出为: %d\n", -num);
		}
}