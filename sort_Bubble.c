#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main() {
    int *ptr, len;
    scanf("%d", &len);
    ptr = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        scanf("%d", ptr + i);

    bubbleSort(ptr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", ptr[i]);
        
    free(ptr);
    ptr = 0;
}