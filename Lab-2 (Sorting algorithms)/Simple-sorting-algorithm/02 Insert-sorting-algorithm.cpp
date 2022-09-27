#include <iostream>

using namespace std;

// https://www.youtube.com/watch?v=JU767SDMDvA

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

void insert_sorting_algorithm(int array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        int j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            // swaping 
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }

            j = j - 1;
        }
    }
}

int main()
{
    int array[] = {2, 1, 5, 9, 4, 7, 3, 8};

    cout << "Array which need to sort:\n";

    print_array(array, 8);

    cout << "Sorted array:\n";

    insert_sorting_algorithm(array, 8);

    print_array(array, 8);

    return 0;
}
