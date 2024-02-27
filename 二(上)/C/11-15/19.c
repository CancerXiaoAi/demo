#include <stdio.h>
int main () {
	int a, b;
	printf("输入整数a: ");
	scanf("%d", &a);
	printf("输入整数b: ");
	scanf("%d", &b);
	if(a > b){
		printf("y的值为: %d\n", 2);
	}
	if(a = b){
		printf("y的值为: %d\n", 1);
	}
	if(a < b){
		printf("y的值为: %d\n", 0);
	}
}