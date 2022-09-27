#include <iostream>
#include <string>

using namespace std;

class tree
{

    private:

        struct node //+
        {
            int data;
            node *left, *right;
        };

    public:
    
        node *root; //+

        tree() //+
        {
            cout << "\nConstructor\n";

            root = NULL;
        }

        node *create_node(int data) //+
        {
            node *leaf = new node;

            leaf->data = data;
            leaf->left = leaf->right = NULL;

            return leaf;
        }

        node *add_node(node *ptr, int data) //+
        {
            if (root == NULL)
            {
                root = create_node(data);
            }
            else if (data < ptr->data)
            {
                if (ptr->left != NULL)
                {
                    add_node(ptr->left, data);
                }
                else
                {
                    ptr->left = create_node(data);
                    return ptr->left;
                }
            }
            else if (data > ptr->data)
            {
                if (ptr->right != NULL)
                {
                    add_node(ptr->right, data);
                }
                else
                {
                    ptr->right = create_node(data);
                    return ptr->right;
                }
            }
            else
            {
                return NULL;
            }
        }

        node *add_nodes(int data[], int size_of_data_array) //+
        {
            for (int i = 0; i < size_of_data_array; i++)
            {
                add_node(root, data[i]);
            }
        }

        node *search_node_iterativity(int data)
        {
            node *current_root = new node;

            current_root = root;

            if (current_root == NULL)
            {
                return NULL;
            }

            while (current_root != NULL && data != current_root->data)
            {
                if (data < current_root->data)
                {
                    current_root = current_root->left;
                }
                else if (data > current_root->data)
                {
                    current_root = current_root->right;
                }
            }

            if (current_root->data == data)
            {
                return current_root;
            }
            else
            {
                return NULL;
            }
        }

        node *search_node_recursively(int data)
        {
            return search_node_recursively(root, data);
        }

        node *search_node_recursively(node *ptr, int data)
        {
            if (ptr == NULL)
            {
                return NULL;
            }
            if (data == ptr->data)
            {
                return ptr;
            }
            if (data < ptr->data)
            {
                return search_node_recursively(root->left, data);
            }
            if (data > ptr->data)
            {
                return search_node_recursively(root->right, data);
            }
        }

        node *delete_node(node *ptr, int data)
        {
            if (ptr == NULL)
            {
                return NULL;
            }
            else if (data < ptr->data)
            {
                ptr->left = delete_node(ptr->left, data);
                return ptr;
            }
            else if (data > ptr->data)
            {
                ptr->right = delete_node(ptr->right, data);
                return ptr;
            }
            if(ptr->data=data)
            {
                // no child +
                if (ptr->left == NULL && ptr->right == NULL)
                {
                    delete ptr;
                    ptr=NULL;
                    return NULL;
                }
                // only right +
                else if (ptr->left == NULL && ptr->right != NULL)
                {
                    node *temp = ptr->right;
                    delete ptr;
                    return temp;
                }
                // only left +
                else if (ptr->left != NULL && ptr->right == NULL)
                {
                    node *temp = ptr->left;
                    delete ptr;
                    return temp;
                }
                // bouth cases -
                else if (ptr->left != NULL && ptr->right != NULL)
                {
                    node *temp = min_node(ptr->right);
                    ptr->data = temp->data;
                    ptr->right = delete_node(ptr->right, temp->data); // not okk
                }
            
            }

            return ptr;
        }

        void delete_subtree(node *ptr) //+
        {
            if (ptr != NULL)
            {
                if (ptr->left != NULL)
                {
                    delete_subtree(ptr->left);
                }
                if (ptr->right != NULL)
                {
                    delete_subtree(ptr->right);
                }

                delete ptr;
            }
        }

        node *min_node(node *ptr) //+
        {
            if (root == NULL)
            {
                return NULL;
            }
            else
            {
                while (ptr->left != NULL)
                {
                    ptr = ptr->left;
                }

                return ptr;
            }
        }

        node *max_node(node *ptr) //+
        {

            if (root == NULL)
            {
                return NULL;
            }
            else
            {
                while (ptr->right != NULL)
                {
                    ptr = ptr->right;
                }

                return ptr;
            }
        }

        void in_order_traversal(node *ptr) //+
        {
            if (root != NULL)
            {
                if (ptr->left != NULL)
                {
                    in_order_traversal(ptr->left);
                }

                cout << ptr->data << " ";

                if (ptr->right != NULL)
                {
                    in_order_traversal(ptr->right);
                }
            }
            else
            {
                cout << endl
                    << "The tree is empty." << endl;
            }
        }

        void print_tree(string prefix, node *ptr, bool isLeft) //+
        {
            if (ptr != NULL)
            {
                cout << "\n"
                    << (prefix + (isLeft ? "|-- " : "\\-- ") + to_string(ptr->data)) << "\n";
                print_tree(prefix + (isLeft ? "|   " : "    "), ptr->left, true);
                print_tree(prefix + (isLeft ? "|   " : "    "), ptr->right, false);
            }
        }

        ~tree() //+
    {
        cout << "\nDestructor\n";
        delete_subtree(root);
    }
};

int main()
{
    tree myTree;

    int array[16]{50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

    cout<<endl<<"Initialize of tree in process:"<<endl;

    cout<<endl<<" - the element of massive added to tree;"<<endl;
    myTree.add_nodes(array, 16);

    
    cout<<endl<<" - in order traversal way:"<<endl;
    myTree.in_order_traversal(myTree.root);

    cout<<endl<<" - check delition of element in different position of tree:"<<endl;

    cout<<endl<<"  - deliting 76"<<endl;
    myTree.delete_node(myTree.root,76);
    myTree.print_tree("   ", myTree.root, true);
    cout<<endl<<"  - deliting 87"<<endl;
    myTree.delete_node(myTree.root,87);
    myTree.print_tree("   ", myTree.root, true);
    cout<<endl<<"  - deliting 2"<<endl;
    myTree.delete_node(myTree.root,2);
    myTree.print_tree("   ", myTree.root, true);


    return 0;
}

// Literature and Resorses:

// https://www.youtube.com/c/PaulProgramming
// https://www.youtube.com/user/mycodeschool
// https://www.youtube.com/watch?v=ujRnhGc1GNw
// https://stackoverflow.com/questions/4965335/how-to-print-binary-tree-diagram-in-java/42449385#42449385
