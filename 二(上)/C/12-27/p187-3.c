#include<stdio.h>
main(){
	void put(int);
	int ascii;
	printf("ÊäÈëÒ»¸öASCIIÂë: ");
	scanf("%d", &ascii);
	put(ascii);
}
void put(int n){
	int i, a;
	for(i=1;i<9;i++){
		a=n+i-1;
		putchar(a);
	}
}