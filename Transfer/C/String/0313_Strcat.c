#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// String Ca

int main ()
{
    char S[] = "abc";
    char T[] = "def";
    strcat(S, T);
    printf("%s\n", S);

    char S2[] = "abc";
    char T2[] = "def";
    strncat(S2, T2, 2);
    printf("%s\n", S2);
}