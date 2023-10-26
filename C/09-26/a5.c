#include <stdio.h>
main(){
	int n1 = 2, n2 = 4;
	float n3, n4;
	n3 = n1 / n2;
	n4 = (float)n1/n2;
	printf("n1/n2=%f\n", n3);
	printf("(float)n1/n2=%f", n4);
}