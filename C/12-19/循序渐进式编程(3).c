#include<stdio.h>
main () {
	int sum (int a, int b, int sum);
	int a, b, s=0, flag=0,i;
	printf("输入整数a: ");
	scanf("%d", &a);
	printf("输入整数b: ");
	scanf("%d", &b);
	for(i=0;i<3;i++){
		printf("输入结果: ");
		scanf("%d", &s);
		if (!sum(a, b, s)){
			printf("right\n");
			flag = 1;
			break;
		}else{
			continue;
		}
	}

	if(flag == 0){
		printf("您的次数已用完!\n");
	}
}
int sum (int a, int b, int sum) {
	if((a+b) == sum){
		return 0;
	}
}