#include<stdio.h>
int main () {
	int i = 0;
	int sum = 0;
	while (i < 100){
		i += 1;
		sum = sum + i;
	}
	printf("%d", sum);
}