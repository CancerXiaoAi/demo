#include <stdio.h>

int main()
{
	char pass[50];
	printf("Input the password: ");
	scanf("%s", pass);

	int i, f1=0, f2=0, f3=0;
	
	// �ж��������� 
	for (i = 0; i < 50; i++) {
		if (pass[i] == '\0') {
			break;
		}
		if (pass[i] >= 48 && pass[i] <= 57) {
			f1 = 1;
				break;
		}
	}
	
	// �ж�������ĸ 
	for (i = 0; i < 50; i++) {
		if (pass[i] == '\0') {
			break;
		}
		if ((pass[i] >= 65 && pass[i] <= 90) || (pass[i] >= 97 && pass[i] <= 122)) {
			f2 = 1;
			break;
		}
	}
	
	// �ж����������ַ� 
	const char scs[20] = "`~!@#$%^&*()_-+=|<>?";
	for (i = 0; i < 50; i++) {
		if (pass[i] == '\0') {
			break;
		}
		int j = 0;
		for (; j < 20; j++) {
			if (pass[i] == scs[j]) {
				f3 = 1;
				break;
			}
		}
	}
	
	// �ж�����ǿ�� 
	if (f1+f2+f3 == 1) printf("������\n");
	if (f1+f2+f3 == 2) printf("�е�����\n");
		else printf("ǿ����\n");
	
	return 0;
}