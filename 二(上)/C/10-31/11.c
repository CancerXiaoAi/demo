#include <stdio.h>
main(){
	float height, weight, bmi;
	printf("请输入身高(m): ");
	scanf("%f", &height);
	printf("请输入体重(kg): ");
	scanf("%f", &weight);
	bmi = weight / (height * height);
	if(bmi >= 18.5 && bmi <= 23.9)
		printf("正常\n");
	else
		printf("不正常\n");
}