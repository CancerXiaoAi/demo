#include <stdio.h>
main(){
	int mark;
	printf("输入分数: ");
	scanf("%d", &mark);
	if(mark<60)
		printf("等级为: E\n");
	if(mark >= 60 && mark <70)
		printf("等级为: D\n");
	if(mark >= 70 && mark <80)
		printf("等级为: C\n");
	if(mark >= 80 && mark <90)
		printf("等级为: B\n");
	if(mark >= 90 && mark <100)
		printf("等级为: A\n");
}