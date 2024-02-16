#include<stdio.h>
main () {
	int i,sum=0,s=1;
	for (i=1;i<=101;i+=2) {
		sum=sum+i*s;
		s=-s;
	}
	printf("%d\n", sum);
}