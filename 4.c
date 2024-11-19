#include <stdio.h>

int main()
{
	char pass[50];
	printf("Input the password: ");
	scanf("%s", pass);

	int i, f1=0, f2=0, f3=0;
	
	// ÅÐ¶ÏÓÐÎÞÊý×Ö 
	for (i = 0; i < 50; i++) {
		if (pass[i] == '\0') {
			break;
		}
		if (pass[i] >= 48 && pass[i] <= 57) {
			f1 = 1;
				break;
		}
	}
	
	// ÅÐ¶ÏÓÐÎÞ×ÖÄ¸ 
	for (i = 0; i < 50; i++) {
		if (pass[i] == '\0') {
			break;
		}
		if ((pass[i] >= 65 && pass[i] <= 90) || (pass[i] >= 97 && pass[i] <= 122)) {
			f2 = 1;
			break;
		}
	}
	
	// ÅÐ¶ÏÓÐÎÞÌØÊâ×Ö·û 
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
	
	// ÅÐ¶ÏÃÜÂëÇ¿¶È 
	if (f1+f2+f3 == 1) printf("ÈõÃÜÂë\n");
	if (f1+f2+f3 == 2) printf("ÖÐµÈÃÜÂë\n");
		else printf("Ç¿ÃÜÂë\n");
	
	return 0;
}