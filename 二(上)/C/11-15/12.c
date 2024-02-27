#include <stdio.h>
int main () {
	int grade;
	printf("输入1~100的整数: ");
	scanf("%d", &grade);
	while (grade < 0 && grade > 100){
		printf("输入1~100的整数: \n");
		scanf("%d", &grade);
	}
	printf("输入的数字是: %d\n", grade);
}