#include<stdio.h>
main () {
	int sum (int a, int b, int sum);
	int a, b, s=0;
	printf("��������a: ");
	scanf("%d", &a);
	printf("��������b: ");
	scanf("%d", &b);
	while (1){
		printf("������: ");
		scanf("%d", &s);
		if (!sum(a, b, s)){
			printf("right\n");
			break;
		}else{
			printf("error\n");
		}
	}
}
int sum (int a, int b, int sum) {
	if((a+b) == sum){
		return 0;
	}
}