#include <stdio.h>
 main() {
    int a[10], count = 0, sum = 0;
    int i;
    printf("Enter 10 numbers: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) {
            count++;
            sum += a[i];
        }
    }
    printf("�Ǹ�������Ϊ: %d\n", count);
    printf("�Ǹ���֮��Ϊ: %d\n", sum);
 }