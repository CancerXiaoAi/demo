#include<stdio.h>
main () {
	int a[]={80,56,83,79,91,58,64,85,90,60};
	int i;
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		printf("%d\n", a[i]);
	}
}