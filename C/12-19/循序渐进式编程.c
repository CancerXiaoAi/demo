#include<stdio.h>
main () {
	int sum (int a, int b, int sum);
	int a, b, sum;
	printf("��������a: ");
	scanf("%d", &a);
	printf("��������b: ");
	scanf("%d", &b);
	printf("������: ");
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