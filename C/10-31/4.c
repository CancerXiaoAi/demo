#include <stdio.h>
main(){
	int num;
	printf("������һ������: ");
	scanf("%d", &num);
	if(num % 3 == 0 && num % 5 == 0)
		printf("%d", num);
}