#include<stdio.h>
int main () {
	int num, sum=0;
	int i=0;
	printf("����5���ɼ�: \n");
	while (i<5) {
		scanf("%d", &num);
		sum += num;
		i++;
	}
	printf("ƽ����Ϊ: %d", sum/5);
}