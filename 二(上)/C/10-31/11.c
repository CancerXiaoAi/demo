#include <stdio.h>
main(){
	float height, weight, bmi;
	printf("���������(m): ");
	scanf("%f", &height);
	printf("����������(kg): ");
	scanf("%f", &weight);
	bmi = weight / (height * height);
	if(bmi >= 18.5 && bmi <= 23.9)
		printf("����\n");
	else
		printf("������\n");
}