#include <stdio.h>
#include<math.h>
int main () {
	int a, b, c;
	printf("���������εı�1: ");
	scanf("%d", &a);
	printf("���������εı�2: ");
	scanf("%d", &b);
	printf("���������εı�3: ");
	scanf("%d", &c); 
	if( a + b > c && a - b < c){
		float s, area;
		s=(a+b+c)/2;
		area=sqrt((s-a)*(s-b)*(s-c)*s);
		printf("���Ϊ: %f", area);
	}else{
		printf("���߲��ܹ���������");
	}
}