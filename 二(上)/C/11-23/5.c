#include<stdio.h>
int main () {
	int i,num,sum;
	sum=0;
	for(i=1;i<=100;i++) {
		printf("�����%d����: ",i);
		scanf("%d", &num);
		sum += num;
		if(sum >= 100000) {
			break;
		}
	}
	printf("����ܶ�ﵽ10��Ԫ\n");
} 