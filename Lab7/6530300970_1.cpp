#include <iostream>
using namespace std;

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *tree, int data)
{
    if (tree == NULL)
    {
        tree = new struct node;
        tree -> value = data;
        tree -> left = NULL;
        tree -> right = NULL;
    }
    else
    {
        if (data > tree -> value)
        {
            tree -> right = insert(tree -> right, data);
        }
        else
        {
            tree -> left = insert(tree -> left, data);
        }
    }
    return tree;
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

void print_LeaveNode(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        print_LeaveNode(tree -> left);
        if (tree -> left == NULL && tree -> right == NULL)
        {
            cout << tree -> value << " ";
        }
        print_LeaveNode(tree -> right);
    }
    return;
}
void print_NonLeaveNode(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        print_NonLeaveNode(tree -> left);
        if (tree -> left != NULL && tree -> right != NULL)
        {
            cout << tree -> value << " ";
        }
        print_NonLeaveNode(tree -> right);
    }
    return;
}

void printAll(struct node *tree)
{
    cout << "Inorder : ";
    print_Inorder(tree);
    cout << endl << endl;
    cout << "Leave : ";
    print_LeaveNode(tree);
    cout << endl << endl;
    cout << "Nonleave : ";
    print_NonLeaveNode(tree);
    cout << endl << endl;
}

int menu(void)
{
    int input;

    cout << "=============MENU=============\n";
    cout << "1) Insert\n";
    cout << "2) Print Inorder, print leave node, print nonleave node\n";
    cout << "3) Delete\n";
    cout << "4) Find\n";
    cout << "5) Exit\n";
    cout << "Please choose > ";
    cin >> input;
    return input;
}

struct node *find_min(struct node *tree)
{
    if(tree == NULL)
    {
        return NULL;
    }
    else 
    {
        if (tree -> left == NULL)
        {
            return tree;
        }
        else
        {
            return find_min(tree -> left);
        }
    }
}

struct node *deleteTree(struct node *tree, int data)
{
    struct node *tmpcell, *child;
    if (tree == NULL)
    {
        cout << "No Node\n";
    }
    else
    {
        if (data < tree -> value)
        {
            tree -> left = deleteTree(tree -> left, data);
        }
        else
        {
            if (data > tree -> value)
            {
                tree -> right = deleteTree(tree -> right, data);
            }
            else
            {
                if(tree -> left != NULL && tree -> right != NULL)
                {
                    tmpcell = find_min(tree -> right);
                    tree -> value = tmpcell -> value;
                    tree -> right = deleteTree(tree -> right, tree -> value);
                }
                else
                {
                    tmpcell = tree;
                    if (tree -> left == NULL)
                    {
                        child = tree -> right;
                    }
                    else
                    {
                        child = tree -> left;
                    }
                    delete(tmpcell);
                    return child;
                }
            }
        }
    }
    return tree;
}

int find(struct node *tree, int data)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        if (tree -> value == data)
        {
            return 1;
        }
        else
        {
            return find(tree -> left, data) + find(tree -> right, data);
        }
        
    }
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
            tree = insert(tree, data);
            cout << "Success!\n";
            break;
        
        case 2:
            printAll(tree);
            break;
        
        case 3:
            cout << "Delete : ";
            cin >> data;
            tree = deleteTree(tree, data);
            cout << "Success!\n";
            break;
        
        case 4:
            cout << "Search : ";
            cin >> data;
            if (find(tree, data) > 0)
            {
                cout << "Found!\n";
            }
            else
            {
                cout << "Not Found!\n";
            }
            break;
        
        case 5:
            cout << "Ok bye!\n";
            break;
        
        default:
            cout << "Invalid Input\n";
            break;
        }
    } while (input != 5);
    return 0;
}