#include <stdio.h>
int main () {
	int num;
	printf("����һ������: ");
	scanf("%d", &num);
	if(num % 2 == 0){
		printf("����%d��ż��\n", num);
	}
	if (num % 2 != 0) {
		printf("����%d������\n", num);
	}
}