#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    char a1 = 'a';
    x = a1;
    a1 = a1 + 3;
    printf("%d\n", x);  // print 'a' ASCII
    printf("%c\n", a1); // print 'a' + 3  = 'd'
}
