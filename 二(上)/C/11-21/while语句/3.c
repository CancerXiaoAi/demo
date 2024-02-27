#include <stdio.h>
int main () {
	int i = 1;
	while (i <= 100) {
		printf("%d", i);
		if (i % 5 == 0) {
			printf("\n");
		}
		i++;
	}
} 