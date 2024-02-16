#include<stdio.h>
main()
{
	int i, sum;
	//error
 	for(i=1,sum=0;i<=100;i++)
 		sum=sum+i;
	//error 
	printf("1+2+...+100=%d", sum);
}