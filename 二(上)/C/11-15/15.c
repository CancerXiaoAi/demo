#include <stdio.h>
int main () {
	int num;
	printf("����һ������: ");
	scanf("%d", &num);
	if(num >= 0) {
		printf("���Ϊ: %d\n", num);
	}else if(num < 0) {
			printf("���Ϊ: %d\n", -num);
		}
}