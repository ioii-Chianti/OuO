#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *name, *command;
    name = (char *)malloc(10);
    command = (char *)malloc(10);
    printf("Enter Sth: ");
    scanf("%s", name);
    printf("Hello, %s\n", name);
    free(name);
    free(command);
}