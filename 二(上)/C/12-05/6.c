#include<stdio.h>
main(){
	int a[5];
	int i;
	printf("����5������: ");
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		scanf("%d", &a[i]);
	}
	printf("˳�����:\n");
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		printf("%d\n", a[i]);
	}
	
	printf("�������:\n");
	for(i=sizeof(a)/sizeof(int)-1;i>=0;i--){
		printf("%d\n", a[i]);
	}
}