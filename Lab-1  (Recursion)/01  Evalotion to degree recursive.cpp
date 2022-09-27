#include <iostream>

using namespace std;

// Піднести до додатного цілого степеня дійсне ненульове число.

int calculation_power(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    else
    {
        return (base * calculation_power(base, power - 1));
    }
}

int main()
{

    cout << endl<< calculation_power(2, 4) << endl;

    return 0;
}
