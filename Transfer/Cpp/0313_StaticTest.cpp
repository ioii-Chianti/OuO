#include <iostream>
using namespace std;

int StaticIn (int i)
{
    static int Renew = 1;
    int BeRe = Renew;
    Renew += i;         // Renew: 2, 4, 8, 16
    cout << "StaticIn = " << BeRe << endl;
    return BeRe;        // BeRe: 1, 2, 4, 8
}

static int Renew;
int StaticOut (int i)
{
    int BeRe = Renew;
    Renew += i;         // Renew: 1, 3, 7, 15
    cout << "StaticOut = " << BeRe << endl;
    return BeRe;        // BeRe: 0, 1, 3, 7  
}

int NoneStatic (int i)
{
    int Renew = 1;
    int BeRe = Renew;
    Renew += i;        // Renew: 2, 3, 5, 9
    cout << "NoneStatic = " << BeRe << endl;
    return BeRe;       // BeRe: 1, 1, 1, 1
}

int main()
{
    int i;
    for (int i = 1; i <= 10; i <<= 1)
    {
        StaticIn(i);
        StaticOut(i);
        NoneStatic(i);
    }
    
    cout << "StaticIn = " << StaticIn(i) << endl;
    cout << "StaticOut = " << StaticOut(i) << endl;
    cout << "NoneStatic = " << NoneStatic(i) << endl;
    // 輸出的時候又多做了一圈，故上次的保留的Renew會再遞給BeRe
}
