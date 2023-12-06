#include<stdio.h>
main(){
	int a=2,b=3;
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
	printf("a=%d,b=%d", a, b);
}