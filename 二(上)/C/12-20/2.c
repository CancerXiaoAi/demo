#include<stdio.h>
int odd_even_Test(int a){
	if(a%2 == 0){
		return 0;
	}else{
		return 1;
	}
}
main (){
	int a;
	printf("input number a: ");
	scanf("%d", &a);
	if(odd_even_Test(a) == 0){
		printf("��ż��\n");
	}
	if(odd_even_Test(a) == 1){
		printf("������\n");
	}
} 