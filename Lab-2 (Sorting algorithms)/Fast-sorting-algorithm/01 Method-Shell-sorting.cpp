#include <iostream>

using namespace std;

// https://xlinux.nist.gov/dads/HTML/shellsort.html

void print_array(int array[], int size)
{
    cout << endl
         << "*******************" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl
         << "*******************" << endl;
}

void shell_sorting_method(int array[], int size)
{
    for (int i = int(size/ 2); i >= 1; i = i/2)
    {
        for (int j = 0, k = i; k < size; j++, k++)
        {
            if (array[j] > array[k])
            {
                // swaping
                {
                    int temp = array[j];
                    array[j] = array[k];
                    array[k] = temp;
                }
            }
            print_array(array, 9);
        }
   
    }
}

int main()
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    shell_sorting_method(array, 9);

    print_array(array, 9);

    return 0;
}