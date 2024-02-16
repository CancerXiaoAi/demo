#include <stdio.h>
int main () {
	int num;
	printf("输入一个整数: ");
	scanf("%d", &num);
	if(num % 2 == 0){
		printf("数字%d是偶数\n", num);
	}else {
		printf("数字%d是奇数\n", num);
	}
}