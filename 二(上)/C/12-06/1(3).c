#include<stdio.h>
main(){
	float price[10]={12.5,28.9,230,121.2,98.9,83.1,10,38.8,52,110};
	int i;
	int sum=0;
	for(i=0;i<sizeof(price)/sizeof(float);i++){
		if(price[i]>=100){
			sum++;
		}
	}
	printf("������100Ԫ����100Ԫ�����ϵ���Ʒ����: %d\n", sum);
}