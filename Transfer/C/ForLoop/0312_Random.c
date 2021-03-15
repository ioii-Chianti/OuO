#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int diceCnt[6] = {0, 0, 0, 0, 0, 0};

    for (int i = 1; i <= 5000; ++i)
    {
        int dice = rand() % 6 + 1;
        switch (dice)
        {
        case 1:
            diceCnt[0]++;
            break;
        case 2:
            diceCnt[1]++;
            break;
        case 3:
            diceCnt[2]++;
            break;
        case 4:
            diceCnt[3]++;
            break;
        case 5:
            diceCnt[4]++;
            break;
        case 6:
            diceCnt[5]++;
            break;
        }
    }
    printf("Point 1: %d times.\n", diceCnt[0]);
    printf("Point 2: %d times.\n", diceCnt[1]);
    printf("Point 3: %d times.\n", diceCnt[2]);
    printf("Point 4: %d times.\n", diceCnt[3]);
    printf("Point 5: %d times.\n", diceCnt[4]);
    printf("Point 6: %d times.\n", diceCnt[5]);
}