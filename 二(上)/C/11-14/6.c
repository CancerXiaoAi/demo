#include <stdio.h>
int main () {
	int x;
	printf("��������x: ");
	scanf("%d", &x);
	if(x > 0){
		printf("sign��ֵΪ: %d\n", 1);
	}
	if(x == 0){
		printf("sign��ֵΪ: %d\n", 0);
	}
	if(x < 0){
		printf("sign��ֵΪ: %d\n", -1);
	}
}