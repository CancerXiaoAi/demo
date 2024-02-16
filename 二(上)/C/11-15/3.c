#include <stdio.h>
#include<math.h>
int main () {
	int a, b, c;
	printf("输入三角形的边1: ");
	scanf("%d", &a);
	printf("输入三角形的边2: ");
	scanf("%d", &b);
	printf("输入三角形的边3: ");
	scanf("%d", &c); 
	if( a + b > c && a - b < c){
		float s, area;
		s=(a+b+c)/2;
		area=sqrt((s-a)*(s-b)*(s-c)*s);
		printf("面积为: %f", area);
	}else{
		printf("三边不能构成三角形");
	}
}