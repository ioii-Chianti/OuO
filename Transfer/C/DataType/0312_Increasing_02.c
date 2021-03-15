#include <stdio.h>
#include <stdlib.h>

int a = 2;

int compute(int a)
{
    printf("%d\n", a++ * a); // 2(++) * 3 = 6
    return (a++ * a);        // 3(++) * 4 = 12
}

int main()
{
    a += compute(a); // a = 2 + 12 = 14
    printf("%d\n", a);
    return 0;
}