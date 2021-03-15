#include <iostream>
using namespace std;

class shape
{ 
    public:
        double getArea(double length, double height)
        {
            return (length * height);
        }
};

class triangle : public shape
{
    public:
        double getArea(double length, double height)
        {
            return (length * height / 2);
        }
        // Override: Method with same name, but redefine its content.
};

int main()
{
    int length, height;
    triangle tri;
    cout << "Enter Length:"; cin >> length;
    cout << "Enter Height:"; cin >> height;
    cout << tri.getArea(length, height);
}