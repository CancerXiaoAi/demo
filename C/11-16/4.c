#include <stdio.h>
int main () {
	int a, b;
	char op;
	printf("按照a,op,b的形式输入: ");
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