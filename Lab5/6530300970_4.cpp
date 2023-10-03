#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string value;
    struct Node *next;
};
typedef struct Node *Stack;

Stack CreateStack(void)
{
    Stack S;
    S = new struct Node;
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

int IsEmpty(Stack S)
{
    return S -> next == NULL;
}

void Push(string X, Stack S)
{
    Stack TempCell;
    TempCell = new struct Node;
    if (TempCell == NULL)
    {
        cout << "Out of space!!!\n";
    }
    else
    {
        TempCell -> value = X;
        TempCell -> next = S -> next;
        S -> next = TempCell;
    }
}

string Top(Stack S)
{
    if (!IsEmpty(S))
    {
        return S -> next -> value;
    }
    else 
    {
        return " ";
    }
}

void Pop(Stack S)
{
    Stack FirstCell;
    if (IsEmpty(S))
    {
        cout << "Empty Stack!!!\n";
    }
    else 
    {
        FirstCell = S -> next;
        S -> next = S -> next -> next;
        delete(FirstCell);
    }
}

void menu(void)
{
    cout << "==========MENU==========\n";
    cout << "1. Infix\n";
    cout << "2. Infix ()\n";
}

Stack option1(Stack S)
{
    string input, temp;
    cout << "Infix : ";
    do
    {
        cin >> input;
        if (input != ".")
        {
            if (input == "+" || input == "-")
            {
                temp = Top(S);
                if (temp != "*" && temp != "/")
                {
                    Push(input, S);
                }
                else
                {
                    while (S -> next != NULL)
                    {
                        temp = Top(S);
                        Pop(S);
                        cout << temp << " ";
                    }
                    Push(input, S);
                }
            }
            else if (input == "*" || input == "/")
            {
                Push(input, S);
            }
            else
            {
                cout << input << " ";
            }
        }
    } while (input != ".");
    while (S -> next != NULL)
    {
        temp = Top(S);
        Pop(S);
        cout << temp << " ";
    }
    return S;
}

Stack option2(Stack S)
{
    string input, temp;
    cout << "Infix : ";
    do
    {
        cin >> input;
        if (input != ".")
        {
            if (input == "+" || input == "-")
            {
                temp = Top(S);
                if (temp != "*" && temp != "/")
                {
                    Push(input, S);
                }
                else
                {
                    while (S -> next != NULL)
                    {
                        temp = Top(S);
                        if (temp == "(")
                        {
                            break;
                        }
                        Pop(S);
                        cout << temp << " ";
                    }
                    Push(input, S);
                }
            }
            else if (input == "*" || input == "/")
            {
                Push(input, S);
            }
            else if (input == "(")
            {
                Push(input, S);
            }
            else if (input == ")")
            {
                temp = Top(S);
                while (temp != "(")
                {
                        temp = Top(S);
                        Pop(S);
                        cout << temp << " ";
                        temp = Top(S);
                        if (temp == "(")
                        {
                            Pop(S);
                        }
                }
            }
            else
            {
                cout << input << " ";
            }
        }
    } while (input != ".");
    while (S -> next != NULL)
    {
        temp = Top(S);
        Pop(S);
        cout << temp << " ";
    }
    return S;
}

int main()
{
    Stack S;
    S = CreateStack();
    int choose;

    menu();
    cout << "Please choose > ";
    cin >> choose;

    switch (choose)
    {
    case 1:
        option1(S);
        break;
    case 2:
        option2(S);
        break;
    
    default:
        cout << "Error invalid input!!\n";
        break;
    }

    return 0;
}