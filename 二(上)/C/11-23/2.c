#include<stdio.h>
int main () {
	int i, sum;
	sum=0;
	for (i=0;i<=100;i++) {
		sum += i;
	}
	printf("1~100µÄÀÛ¼ÓºÍ: %d\n", sum);
}