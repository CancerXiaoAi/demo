#include<stdio.h>
main()
{
	int i, sum;
 	for(i=0,sum=0;i<=100;i++)
 		sum=sum+i;
	//error 
	printf("1+2+...+100=%d", sum);
}