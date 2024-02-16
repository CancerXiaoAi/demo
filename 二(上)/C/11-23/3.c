#include<stdio.h>
int main () {
	int i, sum;
	sum=5;
	for (i=4;i>=1;i--) {
		sum *= i;
	}
	printf("5£¡: %d\n", sum);
}