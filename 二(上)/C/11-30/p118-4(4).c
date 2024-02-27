#include <stdio.h>
int main()
{
    int num, digit, sum;
    printf("Ë®ÏÉ»¨Êı: \n");
    for(num = 100; num <= 999; num++)
    {
        digit = num % 10;
        sum = digit * digit * digit;
        digit = num / 10 % 10;
        sum += digit * digit * digit;
        digit = num / 100;
        sum += digit * digit * digit;
        if(num == sum)
            printf("%d\n", num);
    }
    return 0;
}