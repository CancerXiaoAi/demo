#include<stdio.h>
main(){
	int a[2];
	void s(int[]);
	printf("a[0]=");
	scanf("%d", &a[0]);
	printf("a[1]=");
	scanf("%d", &a[1]);
	s(a);
	printf("a[0]=%d,a[1]=%d\n", a[0], a[1]);
}
void s(int b[]){
	int t;
	t=b[0];
	b[0]= b[1];
	b[1]=t;
}