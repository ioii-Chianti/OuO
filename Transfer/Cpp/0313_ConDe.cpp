#include <iostream>
using namespace std;

class A
{
    public:
        int oid;
        A(int i) { oid = i; }
        ~A() { cout << oid; }
};

void func()
{
    A a2(2); // 2
    static A a3(3); // 3
}

// func() ends, destruct a3, but it's static. 
// Destruct a2, print a2.oid = 2

int main()
{
    A a1(1); // 1
    func();
    return 0;
}

// Destruct a1, print a1.oid = 1
// Destruct ststic a3, print a3.oid = 3