#include <stdio.h>
int main () {
	char t, m, f;
	int ta, ma, fa;
	printf("输入性别: (男生为m 女生为f)");
	scanf("%c", &t);
	printf("输入年龄: ");
	scanf("%d", &ta);
	if(t == 'm') {
		m = t;
		ma = ta;
		if(ma >= 60) {
			printf("您已退休\n");
		}else if(ma <= 0){
			printf("输入的年龄不合法\n");
		}else{
			printf("您还在工作\n");
		}
	}else if(t == 'f'){
		f = t;
		fa = ta;
		if(fa >= 55) {
			printf("您已退休\n");
		} else if(fa <= 0){
			printf("输入的年龄不合法\n");
		}else{
			printf("您还在工作\n");
		}
	}else{
		printf("输入了错误的性别\n");
	}
} 