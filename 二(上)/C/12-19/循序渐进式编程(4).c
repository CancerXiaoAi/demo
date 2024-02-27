#include<stdio.h>
#include<stdlib.h>
main () {
	int sum (int s, int re);
	int a, b, s=0,re, flag=0,i;
	for(i=0;i<10;i++){
		a=rand()%100+1;
		b=rand()%100+1;
		re=a+b;
		printf("%d+%d= ",a ,b);
		scanf("%d", &s);
		if(!sum(s,re)){
			printf("right\n");
			flag ++;
			continue;
		}else{
			continue;
		}
	}
	printf("×Ü·Ö: %d", flag);
}
int sum (int s, int re) {
	if(s == re){
		return 0;
	}
}