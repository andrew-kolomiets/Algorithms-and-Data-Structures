
#include <iostream>
#include <string>

#define line cout<<endl<<"-----------------------------------------------------------------"<<endl;

using namespace std;

int data_;

struct element
{
	int data;
	element* next;
};

element* add_func(element* old_top, int data)
{
	element* top = new element;
	top->next = old_top;
	top->data = data;
	return top;
}

element* delete_func(element* top_)
{
	element* save_;
	save_ = top_->next;
	data_ = top_->data;
	delete  top_;
	return save_;
}


int main()
{
	line
	    element  *current;

		current = new element;
		current->next = NULL;

		cout << endl << "Input the row of equesion: " << endl;
		string arr;		cin >> arr;     int size = arr.length();

		for (int i = 0; i < size; i++)
		{
			if (arr[i] != '+'&&arr[i] != '-'&&arr[i] != '*'&&arr[i] != '/')
			{
				current = add_func(current, ((int)arr[i] - (int)'0'));
			}
			if (arr[i] == '+')
			{
				current = delete_func(current);
				int data_1 = data_;
				current = delete_func(current);
				int data_2 = data_;
				int result = data_1 + data_2;
				current = add_func(current, result);
			}
			if (arr[i] == '-')
			{
				current = delete_func(current);
				int data_1 = data_;
				current = delete_func(current);
				int data_2 = data_;
				int result = data_2 - data_1;
				current = add_func(current, result);
			}
			if (arr[i] == '*')
			{
				current = delete_func(current);
				int data_1 = data_;
				current = delete_func(current);
				int data_2 = data_;
				int result = data_1 * data_2;
				current = add_func(current, result);
			}
			if (arr[i] == '/')
			{
				current = delete_func(current);
				int data_1 = data_;
				current = delete_func(current);
				int data_2 = data_;
				int result = data_2 / data_1;
				current = add_func(current, result);
			}
			
		}
		
		line
			cout << endl << "Result of our operation "<<arr<<" is: " << current->data<<"."<<endl;
		line
	
	return 0;
}


