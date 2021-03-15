#include <iostream>
using namespace std;

class A
{
    public:
        int x = 5;
        int y = 10;

    protected:
        int z = 15;

    private:
        int k = 20;
};

class B : public A {};

int main()
{
    B b;
    cout << b.x;

    return 0;
}