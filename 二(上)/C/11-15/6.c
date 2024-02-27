#include <stdio.h>
int main () {
	int x;
	printf("输入整数x: ");
	scanf("%d", &x);
	if(x > 0){
		printf("sign的值为: %d\n", 1);
	}
	if(x == 0){
		printf("sign的值为: %d\n", 0);
	}
	if(x < 0){
		printf("sign的值为: %d\n", -1);
	}
}