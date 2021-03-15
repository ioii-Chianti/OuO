#include <stdio.h>
#include <stdlib.h>

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 2, b = 3;
    sawp(a, b);
    printf("%d, %d", a, b);
}