#include<stdio.h>
main(){
	float price[10]={12.5,28.9,230,121.2,98.9,83.1,10,38.8,52,110};
	int i;
	float sum;
	for(i=0;i<sizeof(price)/sizeof(float);i++){
		sum+= price[i];
	}
	printf("�ܺ�Ϊ: %f\n", sum);
	printf("ƽ��ֵΪ: %f\n", sum/sizeof(price)/sizeof(float));
}