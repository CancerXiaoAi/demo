#include <stdio.h>
main(){
	float height, weight, bmi;
	printf("���������(m): ");
	scanf("%f", &height);
	printf("����������(kg): ");
	scanf("%f", &weight);
	bmi = weight / (height * height);
	//printf("%f", bmi);
	if(bmi <= 18.4)
		printf("ƫ��\n");
	if(bmi >= 18.5 && bmi <= 23.9)
		printf("����\n");
	if(bmi >= 24.0 && bmi <= 27.9)
		printf("����\n");
	if(bmi >= 28.0)
		printf("����\n");
}