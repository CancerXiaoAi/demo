#include <stdio.h>
int main () {
	char t, m, f;
	int ta, ma, fa;
	printf("�����Ա�: (����Ϊm Ů��Ϊf)");
	scanf("%c", &t);
	printf("��������: ");
	scanf("%d", &ta);
	if(t == 'm') {
		m = t;
		ma = ta;
		if(ma >= 60) {
			printf("��������\n");
		}else if(ma <= 0){
			printf("��������䲻�Ϸ�\n");
		}else{
			printf("�����ڹ���\n");
		}
	}else if(t == 'f'){
		f = t;
		fa = ta;
		if(fa >= 55) {
			printf("��������\n");
		} else if(fa <= 0){
			printf("��������䲻�Ϸ�\n");
		}else{
			printf("�����ڹ���\n");
		}
	}else{
		printf("�����˴�����Ա�\n");
	}
} 