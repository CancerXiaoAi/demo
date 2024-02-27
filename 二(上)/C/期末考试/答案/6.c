#include <stdio.h>
 main() {
    int num1, num2, q, r;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    q = num1 / num2;
    r = num1 % num2;
    printf("商是: %.2f\n", (float)q);
    printf("余数是: %d\n", r);
}
