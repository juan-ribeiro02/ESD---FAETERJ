#include<stdlib.h>
#include<stdio.h>
#include "funcoes.h"

int main()
{
    int a, b, q, r, st;

    printf("Digite os valores:");
    scanf("%d", &a);
    scanf("%d", &b);

    if(divisaoInteira(a, b, &q, &r) == 1)
    {
        printf("%d/%d = %d com resto %d\n", a, b, q, r);
    }
    else
    {
        printf("Error- divisor e 0\n");
    }

    return 0;
}