#include <stdio.h>
main(){
	int int1, int2, int3, add;
	float avg;
	printf("请输入第一个整数:");
	scanf("%d", &int1);
	printf("请输入第二个整数:");
	scanf("%d", &int2);
	printf("请输入第三个整数:");
	scanf("%d", &int3);
	add = int1 + int2 + int3;
	avg = add / 3;
	printf("他们的和为: %d\n平均值为: %f\n", add, avg);
}