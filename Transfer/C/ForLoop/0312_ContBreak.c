#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Continue Test:\n");
    int sum1 = 0;
    for (int i = 2; i <= 10; i += 2)
    {
        if (i == 6)
            continue;
        else
            sum1 += i;
        printf("%d\n", sum1); // �L�A��else�u���U�@��A�Gprintf���ݩ�else
    }

    printf("Break Test:\n");
    int sum2 = 0;
    for (int i = 2; i <= 10; i += 2)
    {
        if (i = 6)
            break;
        else
            sum2 += i;
    }
    printf("%d\n", sum2);
}