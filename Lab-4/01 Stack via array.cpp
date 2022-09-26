
#include <iostream>

#include <string>

#define line cout<<endl<<"-------------------------------------------------------------"<<endl;

using namespace std;

//in this program we realised the LIFO with help of array//

int size_stack;
int element;
int top = -1;

// Add function

void add_func(int* arr,int element)
{
		top = top + 1;
		*(arr+top) = element;
}


// Stack empety

bool Stack_Empty(int *arr)

{
	if (top == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
	
}

// Delete function

int delete_func(int* arr)
{
	if (Stack_Empty(arr))
	{
		cout << "Error underflow!" << endl;
		return 0;
	}
	else
	{
		top = top - 1;
		return arr[top + 1];

	}
}

// Output stack function

void output_func(int* arr)
{
	
	cout << endl<<"Output stack on the screan:" << endl;
	for (int i = 0; i <=top; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

int main()
{
	line
	cout << "How size of stack do you want." << endl;
	
	cin >> size_stack;
	line
	cout << "Input data in stack:" << endl;
	int *arr = new int[size_stack];

	for (int i = 0; i < size_stack; i++)
	{
		cin >> element;
		add_func(arr,element);
	}
	line
		string answer;
		for (;;)
		{
			cout <<endl<< "Do you want delete top element(Yes|No):" << endl;
			cin >> answer;
			if (answer == "Yes")
			{
				cout<<endl<<"Delete element of stack: "<<delete_func(arr)<<endl;
			}
			else {break;}
		}
	line
			output_func(arr);
	line
	delete[] arr;

	return 0;
}

