#include<stdio.h>
main () {
	int sum(int a, int b, int sum);
	int a, b, s;
	printf("输入整数a: ");
	scanf("%d", &a);
	printf("输入整数b: ");
	scanf("%d", &b);
	printf("输入结果: ");
	scanf("%d", &s);
	if(!sum(a, b, s)){
		printf("right\n");
	}else{
		printf("Not correct! Try again!\n");
	}
}
int sum(int a, int b, int sum) {
	if(a+b == sum){
		return 0;
	}
}