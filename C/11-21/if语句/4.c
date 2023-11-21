#include<stdio.h>
int main () {
	int t;
	printf("输入停车的小时数(整数): ");
	scanf("%d", &t);
	if(t < 2) {
		printf("收费5元");
	}else {
		printf("%d", 5 + (t - 2) * 2);
	}
}