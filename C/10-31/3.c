#include <stdio.h>
main(){
	int num;
	printf("请输入一个整数: ");
	scanf("%d", &num);
	if(num % 3 == 0)
		printf("%d", num);
	else
		printf("输入的数字不能被3整除\n");
}