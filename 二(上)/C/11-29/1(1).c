#include<stdio.h>
main(){
	int i,sum;
	sum=0;
	for(i=0;i<=101;i++){
		if(i % 2 == 0) {
			continue;
		}
		sum+=i;
	}
	printf("%d", sum);
}