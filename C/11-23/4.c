#include<stdio.h>
int main () {
	int i,j,k,m;
	for(i=100;i<=999;i++){
		j=i/100;
		k=i%100/10;
		m=i%10;
		if(i == j*j*j+k*k*k+m*m*m) {
			printf("%d\n", i);
		}
	}
}