#include <stdio.h>
#include <stdlib.h>
main(){
int a, b;
printf("请输入第一个数: ");
scanf("%d", &a);
printf("请输入第二个数: ");
scanf("%d", &b);
printf("结果: |%d - %d| = %d\n", a, b, abs(a - b));
}