#include <stdio.h>
main(){
	int num;
	printf("请输入一个整数: ");
	scanf("%d", &num);
	if(num % 2 == 0)
		printf("%d", num);
	else
		printf("输入的数字不能被2整除\n");
}