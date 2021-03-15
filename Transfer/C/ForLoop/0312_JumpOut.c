#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("First Test:\n");
    int x = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
        x = x + i;
    }
    printf("%d\n", x);

    //

    printf("Second Test:\n");
    int sum = 0;
    for (int i = 1; i <= 10; i += 2)
    {
        printf("%d\n", i);
        sum += i;
    }
    printf("%d\n", sum);
}