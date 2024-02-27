#include<stdio.h>
int main () {
	int i,num,sum;
	sum=0;
	for(i=1;i<=100;i++) {
		printf("输入第%d个数: ",i);
		scanf("%d", &num);
		sum += num;
		if(sum >= 100000) {
			break;
		}
	}
	printf("捐款总额达到10万元\n");
} 