#include <stdio.h>
 main() {
    int num1, num2, q, r;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    q = num1 / num2;
    r = num1 % num2;
    printf("����: %.2f\n", (float)q);
    printf("������: %d\n", r);
}
