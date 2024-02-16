#include <stdio.h>
main(){
	int C, F;
	printf("请输入华氏度: ");
	scanf("%d", &F);
	C = 5 / 9.0 * (F - 32);
	printf("摄氏度为: %d\n", C);	
}