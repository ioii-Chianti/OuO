#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 5, y = 5;
    int a, b;
    a = x++;
    b = ++y;
    printf("%d, %d, %d, %d, ", a, b, x, y);
}