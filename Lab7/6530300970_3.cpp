#include <iostream>
using namespace std;

struct node
{
    string value;
    struct node *left;
    struct node *right;
};

struct stack
{
    struct node *tree;
    struct stack *next;
};

typedef struct stack *Stack;

int menu(void)
{
    int input;

    cout << "=============MENU=============\n";
    cout << "1) Insert postorder\n";
    cout << "2) Print Expression tree\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> input;
    return input;
}

Stack createStack(void)
{
    Stack S;
    S = new struct stack;
    if (S == NULL)
    {
        cout << "Out of space!!!\n";
    }
    else
    {
        S -> next = NULL;
    }
    return S;
}

void pop(Stack S)
{
    Stack firstCell;
    if (S -> next == NULL)
    {
        cout << "Empty Stack!!!\n";
    }
    else
    {
        firstCell = S -> next;
        S -> next = S -> next -> next;
        delete(firstCell);
    }
}

void push(Stack S, struct node *T)
{
    Stack tmpCell;
    tmpCell = new struct stack;
    if (tmpCell == NULL)
    {
        cout << "Out of space!!!\n";
    }
    else
    {
        tmpCell -> tree = T;
        tmpCell -> next = S -> next;
        S -> next = tmpCell;
    }
}
struct node *top(Stack S)
{
    if (S -> next != NULL)
    {
        return S -> next -> tree;
    }
    else
    {
        cout << "Empty Stack!!!\n";
        return NULL;
    }
}

struct node *insert(Stack S, struct node *tree, string data)
{
    struct node *node = NULL, *tmpNode = NULL;
    if (tree == NULL)
    {
        tree = new struct node;
        tree -> value = data;
        tree -> left = NULL;
        tree -> right = NULL;
        push(S, tree);
    }
    else
    {
        node = new struct node;
        if (data == "*" || data == "/" || data == "+" || data == "-")
        {
            node -> value = data;
            tmpNode = top(S);
            pop(S);
            node -> right = tmpNode;
            tmpNode = top(S);
            pop(S);
            node -> left = tmpNode;
            push(S, node);
        }
        else
        {
            node -> value = data;
            node -> left = NULL;
            node -> right = NULL;
            push(S, node);
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

void print_Postorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        print_Postorder(tree -> left);
        print_Postorder(tree -> right);
        cout << tree -> value << " ";
    }
    return;
}

void print_tree(struct node *tree)
{   
    cout << "Inorder : ";
    print_Inorder(tree);
    cout << endl << endl;
    cout << "Postorder: ";
    print_Postorder(tree);
    cout << endl << endl;
}

int main()
{
    Stack S = createStack();
    struct node *tree = NULL;
    int input;
    string data;
    do
    {
        input = menu();
        switch (input)
        {
        case 1:
            cout << "Input : ";
            while (data != ".")
            {
                cin >> data;
                if (data != ".")
                {
                    tree = insert(S,tree, data);
                }
            }
            break;
        
        case 2:
            print_tree(top(S));
            break;
        
        case 3:
            cout << "Ok bye!!\n";
            break;
        
        default:
            cout << "Invalid Input!!\n";
            break;
        }
    } while (input != 3);
    
    return 0;
}