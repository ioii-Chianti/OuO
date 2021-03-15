#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char S[] = "abcde";
    char T[] = "abcdg";
    int test = strcmp(S, T);
    printf("%d\n", test);

    // Positive: First bigger; vice versa.

    if (test == 0)
        printf("Equals");
    else if (test > 0)
        printf("First Bigger");
    else
        printf("Second Bigger");
}