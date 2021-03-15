#include <stdio.h>
#include <stdlib.h>

/* Top half is from note,
    and bottom half is from YouTube. */

int main()
{
    int x, *p;
    x = 3;
    p = &x; // p's type: int *
    *p = 5; // *p = *&x = x
    printf("%p\n", p);
    printf("%d\n", x);

    int cnt = 10;
    int *cntAddr = &cnt;
    *cntAddr = 20; // *cntAddr = *&cnt = cnt
    printf("%p\n", cntAddr);
    printf("%d\n", cnt);
}