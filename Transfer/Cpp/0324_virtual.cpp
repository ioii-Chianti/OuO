#include <iostream>
using namespace std;

class Super
{
    public:
        virtual void P()
            { cout << "P.Super\n";
                Q(); }
        virtual void Q()
            { cout << "Q.Super\n"; }

        Super() { P(); }
        virtual ~Super() { P(); }
};

class Sub : public Super
{
    public:
        Sub() { P(); }
        ~Sub() { P(); }
        void Q() { cout << "Q.Sub\n"; }
};

int main()
{
    Super *ptr = new Sub();
    delete (ptr);
}