#include <iostream>

using namespace std;

// Числа  Фібоначчі  fn обчислюються  за  формулами  f0=f1=1; 
// fn=fn-1+fn-2 при n=2,3,... Реалізувати функцію, яка за заданим номером 
// n обчислюватиме значення fn. 


int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    cout << fibonacci(17) << endl;

    return 0;
}
