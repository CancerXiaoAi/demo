#include<stdio.h>
int main () {
	int num, sum=0;
	int i=0;
	printf("输入5个成绩: \n");
	while (i<5) {
		scanf("%d", &num);
		sum += num;
		i++;
	}
	printf("平均数为: %d", sum/5);
}