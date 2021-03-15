#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    int &count = x;
    count += 1;
    cout << x;
}