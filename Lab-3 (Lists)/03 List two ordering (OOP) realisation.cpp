#include <iostream>
#include <string>

using namespace std;

class list
{
private:
    struct element
    {
        element *next;
        element *previous;
        string data;
    };

    element *top, *last, *current;

    int size_list;

public:
    list()
    {
        cout << "\nConstructor. List is created.\n";

        cout << "\nEnter data to element of list:\n";

        top = current = new element;

        cin >> (current->data);

        size_list = 1;

        current->previous = NULL;

        current->next = NULL;
    }

    element &search_element(string data)
    {
        cout << "\nSearch element of list:\n";
        cout << endl;

        current = top;

        while (current != NULL)
        {
            if (this->current->data == data)
            {
                cout << " -element with data: " << this->current->data << " with address " << current << " previous address " << current->previous << " next address " << current->next << endl;
                return *current;
            }
            current = current->next;
        }

        cout << " -element not found\n";

        return *current;
    }

    element &append_element()
    {

        cout << "\nEnter data to element of list:\n";

        element *previous = current;

        current->next = new element;

        current = current->next;
        current->previous = previous;
        current->next = NULL;

        cin >> (current->data);

        size_list++;

        return *current;
    }

    void update_element(element &update_element)
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

    void delete_element(string data)
    {
        cout << "\nDelete element of list:\n"<<endl;

        this->current = top;

        while (this->current != NULL)
        {
            if (current->data == data)
            {

                element *_prev = current->previous;
                element *_nex = current->next;

                if (current->previous == NULL && current->next == NULL)
                {
                    cout << " -list empety\n";
                    delete current;
                    break;
                }
                if (current->previous == NULL)
                {
                    cout << "-deleted start list\n";
                    element *temp = current->next;
                    temp->previous = NULL;
                    delete current;
                    top = current = temp;
                    break;
                }
                if (current->next == NULL)
                {
                    cout << "-deleted end list\n";
                    element *temp = current->previous;
                    temp->next = NULL;
                    delete current;
                    current = temp;
                    break;
                }
                if (current->previous != NULL && current->next != NULL)
                {
                    cout<<" -deleting inner element\n";
                    
                    _nex->previous=_prev;
                    _prev->next=_nex;
                   
                    delete current;

                    current=_prev;

                    break;
                }
                else
                {
                    cout << "-nothing to delete\n";
                    break;
                }
            }
            current = current->next;
        }
    }

    ~list()
    {

        cout << "\nDestructor. List is deleted.\n";

        current = top;

        while (current != NULL)
        {
            element *temp = current->next;

            delete current;

            top=current = temp;
        }
    }

    void print_list()
    {
        cout << "\nPrint all element of list:\n";
        cout << endl;

        current = top;

        while (current != NULL)
        {
            cout << " -element with data: " << this->current->data << " with address " << current << " previous address " << current->previous << " next address " << current->next << endl;
            current = current->next;
        }
    }

    void size_of_list()
    {
        cout << "\nSize of list is: " << size_list << endl;
    }
};

int main()
{
    list a;

    a.append_element();
    a.append_element();
    a.append_element();
    a.append_element();
    a.append_element();
    a.append_element();
    a.print_list();

    a.update_element(a.search_element("3"));
    a.delete_element("1");
    a.delete_element("7");
    a.delete_element("4");

    a.print_list();

    return 0;
}