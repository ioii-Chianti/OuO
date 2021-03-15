#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int input = 0;
    int remain = 0;

    printf("Enter an Integer: ");
    scanf("%d", &input);

    remain = input % 2;
    if (remain == 1)
        printf("%d is odd.\n", input);

    else
        printf("%d is even.\n", input);

    return 0;
}