#include<stdio.h>
int main () {
	int num;
	int i=0;
	int arr[5];
	int index;
	printf("����5���ɼ�: \n");
	while (i<5) {
		scanf("%d", &num);
		arr[i] = num;
		i++;
	}
	int max=arr[0];
	for (index=0;index<5;index++) {
		if(arr[index] > max) {
			max = arr[index];
		}
	}
	printf("���ֵΪ: %d\n", max);
}