#include <stdio.h>
int main () {
	char c;
	printf("����һ����ĸ: ");
	scanf("%c", &c);
	if(c >= 'A' && c <= 'Z'){
		printf("���Ϊ: %c\n", c + 32);
	}else{
		printf("���Ϊ: %c\n", c);
	}
}