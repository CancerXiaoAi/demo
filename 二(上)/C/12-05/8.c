#include<stdio.h>
main(){
	int a[5];
	int i;
	int sum=0;
	printf("����5������: ");
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		sum += a[i];
	}
	printf("�ܺ�Ϊ: %d\n", sum);
	printf("ƽ����Ϊ: %d\n", sum/(sizeof(a)/sizeof(int)));
}