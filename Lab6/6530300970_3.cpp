#include <iostream>
using namespace std;

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *tree, int x)
{
    if (tree == NULL)
    {
        tree = new struct node;
        tree -> value = x;
        tree -> left = NULL;
        tree -> right = NULL;
    }
    else if (x < tree -> value)
    {
        tree->left = insert(tree -> left, x);
    }
    else if (x > tree -> value)
    {
        tree->right = insert(tree -> right, x);
    }
    return tree;
}

void printPreorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        cout << tree -> value << " ";
        printPreorder(tree -> left);
        printPreorder(tree -> right);
    }
    return;
}

void printInorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        printInorder(tree -> left);
        cout << tree -> value << " ";
        printInorder(tree -> right);
    }
    return;
}

void printPostorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        printPostorder(tree -> left);
        printPostorder(tree -> right);
        cout << tree -> value << " ";
    }
    return;
}
void printAll(struct node *tree)
{
    cout << "Preorder : ";
    printPreorder(tree);
    cout << endl;
    cout << "Inorder : ";
    printInorder(tree);
    cout << endl;
    cout << "Postorder : ";
    printPostorder(tree);
    cout << endl;
}

void menu(void)
{
    cout << "========MENU========\n";
    cout << "1) Insert\n";
    cout << "2) Print\n";
    cout << "3) Find min\n";
    cout << "4) Exit\n\n";
    cout << "Please choose > ";
}

struct node *find_min(struct node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (tree -> left == NULL)
    {
        return tree;
    }
    else
    {
        return (find_min(tree -> left));
    }
}

int main()
{
    struct node *tree = NULL;
    int input, x;
    do
    {
        menu();
        cin >> input;
        cout << endl;
        switch (input)
        {
        case 1:
            cout << "Enter : ";
            cin >> x;
            tree = insert(tree, x);
            break;
        
        case 2:
            printAll(tree);
            break;
        
        case 3:
            cout << "Min = " << find_min(tree) -> value << endl;
            break;
        
        case 4:
            cout << "OK! bye\n";
            break;
        
        default:
            cout << "Invalid input!!\n";
            break;
        }
    } while (input != 4);
    
    
    return 0;
}