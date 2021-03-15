#include <stdio.h>
#include <stdlib.h>

int main()
{
    int S[5] = {1, 2, 3, 4, 5};
    int *p, *ptr;
    p = S;
    ptr = S + 2;

    printf("%d\n", *p++);       // Take value, then the p++ (relocate)
    printf("%d\n", (*p)++);     // Take value, then the value ++
    printf("%d\n", ++*p);       // ++ value , then take the value
    printf("%d\n", *++p);       // ++p (relocate), the take the value
    printf("%d\n", *(S + 4));   // S + 4 (relocate), then take the value
    printf("%d\n", ptr[0]);     // ptr = S+2 , ptr[0] = *(S+2)
    printf("%d\n", *++ptr);     // ++ptr (relocate) , then take the value
    printf("%d\n", *(ptr + 1)); // ptr+1 (relocate) , the take the value, equals to the previous!
}