#include <iostream>
#include <string>

using namespace std;

class list
{
private:
    struct element
    {
        element *next;
        string data;
    };

    element *top;

    element *current;

    int size_list;

public:
    list() //+
    {
        cout << "\nConstructor. List is created.\n";

        cout << "\nEnter data to element of list:\n";

        top = current = new element;

        cin >> (current->data);

        size_list = 1;

        current->next = NULL;
    }

    element &search_element(string data) //+
    {
        cout << "\nSearch element of list:\n";
        cout << endl;

        current = top;

        while (current != NULL)
        {
            if (this->current->data == data)
            {
                cout << " -element with data: " << this->current->data << " with address " << current << " next address " << current->next << endl;
                return *current;
            }
            current = current->next;
        }

        cout << " -element not found\n";

        return *top;
    }

    void insert()
    {
        cout << "\nEnter data to element of list:\n";

        current->next = new element;

        current = current->next;

        cin >> (current->data);

        size_list++;

        current->next = NULL;
    }

    void update_element(element &update_element) //+
    {
        cout << "\nUpdate element of list:\n";

        current = top;

        while (current != NULL)
        {
            if (current == &update_element)
            {
                cout << " -insert new data: ";
                cin >> current->data;
                cout << "\n";
                break;
            }
            current = current->next;
        }
    }

    void delete_element(element &delete_element) //+
    {
        cout << "\nDelete element of list:\n"
             << endl;

        element *previous = NULL;

        current = top;

        while (current != NULL)
        {

            if (current == &delete_element)
            {
                
                if (current == top)
                {
                    top = current->next;
                    delete current;
                    current = top;
                    break;
                }
                if (current->next == NULL)
                {
                    previous->next = NULL;
                    delete current;
                    current = previous;
                    break;
                }
                if (current->next != NULL || current != top)
                {
                    previous->next = current->next;
                    delete current;
                    current = previous;
                    break;
                }
            }
            previous = current;
            current = current->next;
        }

        
    }

    void print_list() //+
    {
        cout << "\nPrint all element of list:\n";
        cout << endl;

        current = top;

        while (current != NULL)
        {
            cout << " -data: " << current->data << " with address " << current << " next address " << current->next << " \n"
                 << endl;
            current = current->next;
        }
    }

    void size_of_list() //+
    {
        cout << "\nSize of list is: " << size_list << endl;
    }

    ~list() //+
    {

        cout << "\nDestructor. List is deleted.\n";

        current = top;

        while (current != NULL)
        {
            element *temp = current->next;

            delete current;

            current = temp;
        }
    }
};

int main()
{
    list a;

    a.insert();
    a.insert();
    a.insert();
    a.insert();
    a.insert();
    a.insert();
    a.insert();

    a.print_list();

    a.search_element("1");
    a.search_element("2");
    a.search_element("5");
    a.search_element("8");

    a.update_element(a.search_element("1"));
    a.update_element(a.search_element("5"));
    a.update_element(a.search_element("8"));

    a.print_list();

    a.delete_element(a.search_element("21"));
    a.delete_element(a.search_element("3"));
    a.delete_element(a.search_element("21"));

    a.print_list();

    return 0;
}