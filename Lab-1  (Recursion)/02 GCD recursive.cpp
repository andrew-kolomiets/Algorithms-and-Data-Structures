#include <iostream>

using namespace std;

// Знайти НСД двох цілих чисел за алгоритмом Евкліда.

int gcd(int a, int b)
{
    int r=a%b;

    if(r==0)
    {
        return b;
    }
    else
    {
        gcd(b, r);
    }
}



int main()
{
    cout << endl<< gcd(75, 12) << endl;

    return 0;
}