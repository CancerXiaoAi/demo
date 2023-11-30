#include<stdio.h>
main()
{
	int i, sum;
	//error
	i=0;
 	sum=0;
 	do{
		i++;
		sum = sum + i;
		//error
	 }while(i < 100); 
	//error 
	printf("1+2+...+100=%d", sum);
}