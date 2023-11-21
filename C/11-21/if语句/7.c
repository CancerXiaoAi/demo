#include<stdio.h>
 int main(){
 int a,b;
 char opr;
 printf("请输入两个数: ");
 scanf("%d %d",&a,&b);
 getchar();
 scanf("%c",&opr);
 switch(opr){
	case '+':
		printf("%d+%d=%d\n",a,b,a+b);
		break;
		
	case '-':
		printf("%d-%d=%d\n",a,b,a-b);
		break;
	case '*':
		printf("%d*%d=%d\n",a,b,a*b);
		break;
	case '/':
		printf("%d/%d=%d\n",a,b,a/b);
		break;
	case '%':
		printf("%d%%%d=%d\n",a,b,a%b);
		break;
	default:
		printf("这不是一个正常的运算符! *^*\n");
		break;
	}
 }