#include <stdio.h>
#include <stdlib.h>
main(){
int a, b;
printf("�������һ����: ");
scanf("%d", &a);
printf("������ڶ�����: ");
scanf("%d", &b);
printf("���: |%d - %d| = %d", a, b, abs(a - b));
}