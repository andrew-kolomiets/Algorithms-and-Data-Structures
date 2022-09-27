#include <iostream>

using namespace std;

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

void fast_sorting(int array[], int left, int right)
{
    int i = left;
    int j = right;

    // if (abs(left - j) == 0&& abs(i - right) == 0)
    // {
    //     return;
    // }


    int pivot = array[left + (abs(right - left + 1) >> 1)];

    while (i <= j)
    {
        while (array[i] < pivot)
        {
            ++i;
        }

        while (array[j] > pivot)
        {
            --j;
        }

        if (i <= j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            ++i;
            --j;
        }
    }

    if (j > left)
    {
        fast_sorting(array, left, j);
    }

    if (i < right)
    {
        fast_sorting(array, i, right);
    }
}

int main()
{
    int array[] = {2, 1, 5, 9, 4, 7, 3, 8};

    cout << "Array which need to sort:\n";

    print_array(array, 8);

    cout << "Sorted array:\n";

    fast_sorting(array, 0, 7);

    print_array(array, 8);

    return 0;
}
