#include<stdio.h>
main(){
	int a[5];
	int i;
	printf("����5������: ");
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		scanf("%d", &a[i]);
	}
	printf("a[4]��:\n");
	printf("%d\n", a[4]);
	printf("�����еĵ�һ��������:\n");
	printf("%d\n", a[0]);
}