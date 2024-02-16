#include<stdio.h>
main(){
	int a[10];
	int i;
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		a[i]=i;
	}
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		printf("%d\n", a[i]);
	}
}