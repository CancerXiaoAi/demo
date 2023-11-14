#include <stdio.h>
int main () {
	int a, b, max;
	printf("输入整数a: ");
	scanf("%d", &a);
	printf("输入整数b: ");
	scanf("%d", &b);
	if (a > b) {
		max = a;
	}else {
		max = b;
	}
	printf("最大值为: %d\n", max);
} 