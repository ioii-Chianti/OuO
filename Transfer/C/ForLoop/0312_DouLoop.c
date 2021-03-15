#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    for (i = 1; i <= 3; i++)
    {
        for (j = 5; j <= 6; j++)
        {
            printf("%d", i);
            printf("%d", j);
            printf(" ");
        }
        printf("$");
    }
}