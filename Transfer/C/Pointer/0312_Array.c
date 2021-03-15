#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[] = {10, 20, 30, 40, 50};

    // for (int i = 0; i <= 4; i++)
    // {
    //     printf("%d\n", A[i]);
    // }
    // Use loop to print array.

    printf("%d\n", A[1]); // print A[1]'s value
    printf("%p\n", A);    // A = &A[0] , A is fixed
    printf("%p\n", &A[0]);
    printf("%p\n", &A[1]);
}