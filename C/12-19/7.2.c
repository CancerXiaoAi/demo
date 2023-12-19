#include<stdio.h>
main () {
	int max (int a, int b);
	int a, b;
	printf("输入整数a: ");
	scanf("%d", &a);
	printf("输入整数b: ");
	scanf("%d", &b);
	printf("最大的数是: %d", max(a, b));
}
int max (int a, int b) {
	if (a > b){
		return a;
	}
	if (b > a){
		return b;
	}
}