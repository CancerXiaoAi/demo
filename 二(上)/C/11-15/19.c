#include <stdio.h>
int main () {
	int a, b;
	printf("��������a: ");
	scanf("%d", &a);
	printf("��������b: ");
	scanf("%d", &b);
	if(a > b){
		printf("y��ֵΪ: %d\n", 2);
	}
	if(a = b){
		printf("y��ֵΪ: %d\n", 1);
	}
	if(a < b){
		printf("y��ֵΪ: %d\n", 0);
	}
}