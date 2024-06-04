#include <stdio.h>

int loop1() {
	int sum = 0;
	int i;
	for (i = 0; i < 100; i++) {
		sum += i;
	}
	
	return sum;
}

int loop2() {
	int sum = 0;
	int i = 0;
	while (i < 100) {
		sum += i;
		i++;
	}
	
	return sum;
}

int loop3() {
	int sum = 0;
	int i = 0;
	do {
		sum += i;
		i++;
	}while (i < 100);
	
	return sum;
}

int max(int a, int b, int c, int d, int e) {
	int arr[] = {a, b, c, d, e};
	int max = arr[0];
	int i;
	
	for (i = 0; i < 5; i++) {		
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int min(int a, int b, int c, int d, int e) {
	int arr[] = {a, b, c, d, e};
	int min = arr[0];
	int i;
	
	for (i = 0; i < 5; i++) {		
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

void student(int a, int b, int c, int d, int e) {
	int total = a + b + c + d +e;
	printf("Total: %d\n", total);
	printf("Avrage: %.2f\n", (float)total / 5);
	printf("Maximum: %d\n", max(a, b, c, d, e));
	printf("Minimum: %d\n", min(a, b, c, d, e));
}

int main() {
	printf("loop1 result: %d\n", loop1());
	printf("loop2 result: %d\n", loop2());
	printf("loop3 result: %d\n", loop3());
	printf("=========================\n");
	int a, b, c, d, e;
	printf("Input the first student score: ");
	scanf("%d", &a);
	printf("Input the seceondstudent score: ");
	scanf("%d", &b);
	printf("Input the third student score: ");
	scanf("%d", &c);
	printf("Input the fourth student score: ");
	scanf("%d", &d);
	printf("Input the fifth student score: ");
	scanf("%d", &e);
	student(a, b, c, d, e);
	return 0;
}