#include<stdio.h>
main(){
	int a[] = {11,22,33,44,55};
	int i;
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		printf("%d\n", a[i]);
	}
}