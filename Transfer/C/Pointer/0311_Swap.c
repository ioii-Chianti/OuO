#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main(void)
{
   int a = 10, b = 20;
   printf("Before Swap, ");
   printf("a = %d, b = %d\n", a, b);

   swap(&a, &b);
   printf("After Swap, ");
   printf("a = %d, b = %d\n", a, b);

   return 0;
}

void swap(int *x, int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}