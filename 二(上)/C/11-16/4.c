#include <stdio.h>
int main () {
	int a, b;
	char op;
	printf("����a,op,b����ʽ����: ");
	scanf("%d,%c,%d", &a,&op,&b);
	switch (op) {
		case '+':
			printf("%d%c%d=%f", a, op, b, (float)(a+b));
			break;
		case '-':
			printf("%d%c%d=%f", a, op, b, (float)(a-b));
			break;
		case '*':
			printf("%d%c%d=%f", a, op, b, (float)(a*b));
			break;
		case '/':
			printf("%d%c%d=%f", a, op, b, (float)(a/b));
			break;
	}
}