#include<stdio.h>
int main () {
	int num;
	int i=0;
	int arr[5];
	int index;
	printf("输入5个成绩: \n");
	while (i<5) {
		scanf("%d", &num);
		arr[i] = num;
		i++;
	}
	int min=arr[0];
	for (index=0;index<5;index++) {
		if(arr[index] < min) {
			min = arr[index];
		}
	}
	printf("最小值为: %d\n", min);
}