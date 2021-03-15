#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *ptr, int len) {
    int pivot;
    for (int i = 1; i < len; i++) {
        pivot = *(ptr + i);
        int j = i - 1;
        while (pivot < *(ptr + j) && j >= 0) {
            *(ptr + j + 1) = *(ptr + j);
            j--;
        }
        *(ptr + j + 1) = pivot;
    }
}

int main() {
    int *ptr, len;
    scanf("%d", &len);
    ptr = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        scanf("%d", &*(ptr + i));

    insertionSort(ptr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", *(ptr + i));

    ptr = 0;
}