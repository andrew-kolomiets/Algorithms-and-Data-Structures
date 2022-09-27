#include <iostream>

using namespace std;

// https://www.youtube.com/watch?v=xli_FI7CuzA

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

void bubble_sort(int array[], int size)
{

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // swaping
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}

int main()
{
    int array[] = {2, 1, 5, 9, 4, 7, 3, 8};

    cout << "Array which need to sort:\n";

    print_array(array, 8);

    cout << "Sorted array:\n";

    bubble_sort(array, 8);

    print_array(array, 8);

    return 0;
}
