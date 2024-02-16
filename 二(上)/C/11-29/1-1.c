#include<stdio.h>
main () {
	int a, sum;
	sum=0;
	for(a=0;a<=100;a++){
		sum+=a;
	}
	printf("%d\n", sum);
}