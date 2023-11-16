#include<stdio.h>
int main () {
	int i = 0;
	int sum = 0;
	do {
		i += 1;
		sum = sum + i;
	}while (i < 100);
	printf("%d", sum);
}