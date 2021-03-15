#include <iostream>
using namespace std;

void func()
{
    static int i = 20;
    i += 1;
    cout << i << endl;
}

// Static variable will not be recycled.

int main()
{
    func();
    func();
    return 0;
}