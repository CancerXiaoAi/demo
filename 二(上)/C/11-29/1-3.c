#include<stdio.h>
main(){
	int i,sum;
	sum=0;
	i=0;
	do{
		sum+=i;
		i++;
	} 
	while(i<=100);
	printf("%d", sum);
}