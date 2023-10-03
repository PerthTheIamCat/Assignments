#include <iostream>
using namespace std;

// Written By Pawit Thongkum
// ID : 6530300970
// NO : 3

struct Node
{
    int value;
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

void Push(int X, Stack S)
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

void Top(Stack S)
{
    if (!IsEmpty(S))
    {
        cout << "Top : " << S -> next -> value << endl;
    }
    else 
    {
        cout << "Empty Stack!!!\n";
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
        cout << "Pop : " << FirstCell -> value << endl;
        delete(FirstCell);
    }
}

int menu(void)
{
    int input;
    cout << "==============MENU==============\n";
    cout << "1) Push\n";
    cout << "2) Pop\n";
    cout << "3) Top\n";
    cout << "4) Exit\n";
    cout << "Please choose > ";
    cin >> input;

    return input;
}

int main()
{
    Stack S = NULL;
    int input, data;
    S = CreateStack();
    
    do
    {
        input = menu();
        switch (input)
        {
        case 1:
            cout << "Push : ";
            cin >> data;
            Push(data, S);
            cout << "Success!\n";
            break;

        case 2:
            Pop(S);
            break;

        case 3:
            Top(S);
            break;

        case 4:
            cout << "OK bye!\n";
            break;

        default:
            cout << "Invalid Input\n";
            break;
        }
    } while (input != 4);
    return 0;
}