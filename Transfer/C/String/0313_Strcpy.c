#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// String Copy

int main()
{
    char S[] = "string copy";
    char T[20];
    strcpy(T, S);
    printf("%s\n", T);

    char S2[] = "string copy";
    char T2[20];
    strncpy(T2, S2, 9);
    printf("%s\n", T2);
}