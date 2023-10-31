#include <stdio.h>
main(){
	int num;
	printf("请输入一个整数: ");
	scanf("%d", &num);
	if(num % 3 == 0 && num % 5 == 0)
		printf("%d", num);
	else
		printf("输入的数字不符合要求\n");
}