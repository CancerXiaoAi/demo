#include<stdio.h>
main(){
	int x, y, z, t, m;
	int max(int, int);
	scanf("%d,%d,%d", &x, &y, &z);
	t=max(x, y);
	m=max(t, z);
	printf("%d", m);
}
int max(int a, int b){
	if(a>b){
		return(a);
	}else{
		return(b);
	}
}