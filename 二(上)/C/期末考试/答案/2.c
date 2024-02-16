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
    printf("非负数个数为: %d\n", count);
    printf("非负数之和为: %d\n", sum);
 }