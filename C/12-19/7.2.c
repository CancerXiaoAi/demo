#include<stdio.h>
main () {
	int max (int a, int b);
	int a, b;
	printf("��������a: ");
	scanf("%d", &a);
	printf("��������b: ");
	scanf("%d", &b);
	printf("��������: %d", max(a, b));
}
int max (int a, int b) {
	if (a > b){
		return a;
	}
	if (b > a){
		return b;
	}
}