#include<stdio.h>
main()
{
	int i, sum;
	i=1;
 	sum=0;
 	do{
		sum = sum + i;
		i++;
	 }while(i <= 100); 
	//error 
	printf("1+2+...+100=%d", sum);
}