#include<stdio.h>
 int main(){
 int a,b;
 char opr;
 printf("������������: ");
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
		printf("�ⲻ��һ�������������! *^*\n");
		break;
	}
 }