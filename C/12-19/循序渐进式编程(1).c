#include<stdio.h>
main () {
	int sum(int a, int b, int sum);
	int a, b, s;
	printf("��������a: ");
	scanf("%d", &a);
	printf("��������b: ");
	scanf("%d", &b);
	printf("������: ");
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