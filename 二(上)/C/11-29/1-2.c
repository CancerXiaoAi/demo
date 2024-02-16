#include<stdio.h>
main(){
	int i,sum;
	sum=0;
	i=0;
	while(i<=100){
		sum+=i;
		i++;
	}
	printf("%d", sum);
}