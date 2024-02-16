#include <stdio.h>
main(){
	float height, weight, bmi;
	printf("请输入身高(m): ");
	scanf("%f", &height);
	printf("请输入体重(kg): ");
	scanf("%f", &weight);
	bmi = weight / (height * height);
	//printf("%f", bmi);
	if(bmi <= 18.4)
		printf("偏瘦\n");
	if(bmi >= 18.5 && bmi <= 23.9)
		printf("正常\n");
	if(bmi >= 24.0 && bmi <= 27.9)
		printf("过重\n");
	if(bmi >= 28.0)
		printf("肥胖\n");
}