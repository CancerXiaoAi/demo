#include<stdio.h>
main () {
	int sum (int a, int b, int sum);
	int a, b, sum;
	printf("输入整数a: ");
	scanf("%d", &a);
	printf("输入整数b: ");
	scanf("%d", &b);
	printf("输入结果: ");
	scanf("%d", &sum);
	if(sum(a, b, sum)){
		printf("right");
	}else{
		printf("Not correct! Try again!");
	}
}
int sum (int a, int b, int sum) {
	if((a+b) == sum){
		return 0;
	}
}