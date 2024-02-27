#include<stdio.h>
main(){
	int max(int a, int b);
	int a, b, c, d, m;
	scanf("%d,%d,%d,%d", &a, &b, &c, &d);
	m=max(a, b);
	m=max(m, c);
	m=max(m, d);
	printf("max: %d", m);
}
int max(int a, int b) {
	return a>b?a:b;
}