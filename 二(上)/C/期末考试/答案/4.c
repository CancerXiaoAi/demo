#include <stdio.h>
main() {
	int i,sum=0;
	for (i=0;i<100;i++){
		if(i%3==0){
			sum+=i;
		}
	}
	printf("1~100之中3的倍数之和为: %d\n", sum);
}