#include <iostream>
using namespace std;

struct node
{
    int value;
    int height;
    struct node *left;
    struct node *right;
};

int find_height(struct node *p)
{
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        return p -> height;
    }
}

struct node *insert(int data, struct node *t)
{
    if (t == NULL)
    {
        t = new struct node;
        t -> value = data;
        t -> left = NULL;
        t -> right = NULL;
        t -> height = 0;
    }
    else
    {
        if (data < t -> value)
        {
            t -> left = insert(data, t -> left);
        }
        else
        {
            t -> right = insert(data, t -> right);
        }
    }
    t -> height = (max(find_height(t -> left), find_height(t -> right)) + 1);
    return t;
}

void print_Inorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        print_Inorder(tree -> left);
        cout << tree -> value << " ";
        print_Inorder(tree -> right);
    }
    return;
}

int menu(void)
{
    int input;

    cout << "=============MENU=============\n";
    cout << "1) Insert\n";
    cout << "2) Print Inorder\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> input;
    return input;
}

int main()
{
    struct node *tree = NULL;
    int input, data;
    do
    {
        input = menu();
        switch (input)
        {
        case 1:
            cout << "Enter : ";
            cin >> data;
            tree = insert(data, tree);
            if ((find_height(tree -> left) - find_height(tree -> right)) == 2)
            {
                cout << "\nYou have to rotate trees!\n";
                return 0;
            }
            else
            {
                if ((find_height(tree -> right) - find_height(tree -> left)) == 2)
                {
                    cout << "\nYou have to rotate trees!\n";
                    return 0;
                }
                else
                {
                    cout << "\nSuccess!\n";
                }
            }
            break;
        
        case 2:
            cout << "Inorder : ";
            print_Inorder(tree);
            cout << endl << endl;
            break;
        
        case 3:
            cout << "OK bye!\n";
            break;
        
        default:
            cout << "Invalid Input\n";
            break;
        }
    } while (input != 3);

    return 0;
}