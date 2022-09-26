#include <iostream>

using namespace std;

// https://www.youtube.com/watch?v=g-PGLbMth_g

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

void selection_sorting_algorithm(int array[], int size)
{
    for (size_t j = 0; j < size - 1; j++)
    {
        int imin = j;

        for (size_t i = j + 1; i < size; i++)
        {
            if (array[i] < array[imin])
            {
                imin = i;
            }
        }

        if (imin != j)
        {
            // swaping
            {
                int temp = array[j];
                array[j] = array[imin];
                array[imin] = temp;
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

    selection_sorting_algorithm(array, 8);

    print_array(array, 8);

    return 0;
}
