#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p = 10;
    int *ptr1 = &p;
    int **ptr2 = &ptr1;

    printf("%d\n", p);
    printf("%p\n", &p);
    printf("%d\n", *ptr1);
    printf("%p\n", ptr1);
    printf("%p\n", &ptr1);
    printf("%p\n", *ptr2);
    printf("%d\n", **ptr2);
    printf("%p\n", ptr2);
    printf("%p\n", &ptr2);
}