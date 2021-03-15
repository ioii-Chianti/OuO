#include <stdio.h>
#include <stdlib.h>

int main()
{
    char S[] = "Bnoxqhfgs";
    char *p;
    for (p = S; *p; p++)
    {
        ++*p;
        printf("%c", *p);
    }
    printf("\n%s", S);
}