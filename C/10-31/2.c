#include <stdio.h>
main(){
	int num;
	printf("请输入一个整数: ");
	scanf("%d", &num);
	if(num % 2 == 0)
		printf("%d", num);
}