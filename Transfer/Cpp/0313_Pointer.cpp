#include <iostream>
using namespace std;

void A(int V1, int V2)
{
    int tmp = V2;
    V2 = V1 + 3;
    V1 = tmp + 3;
}

void ptrA(int *V1, int *V2)
{
    int tmp = *V2;
    *V2 = *V1 + 2;
    *V1 = tmp - 4;
}

void refA(int &V1, int &V2)
{
    int tmp = V2;
    V2 = V1 + 4;
    V1 = tmp - 5;
}

int main()
{
    int i = 1;
    int j = 2;
    cout << i << " " << j << endl;
    A(i, j);
    cout << i << " " << j << endl;
    ptrA(&i, &j);
    cout << i << " " << j << endl;
    refA(i, j);
    cout << i << " " << j << endl;
}