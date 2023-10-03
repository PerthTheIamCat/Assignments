#include <iostream>
using namespace std;

struct Node
{
    char value;
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

char Top(Stack S)
{
    if (!IsEmpty(S))
    {
        return S -> next -> value;
    }
    else 
    {
        cout << "Empty Stack!!!\n";
        return ' ';
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

int main()
{
    Stack S;
    int count = 0;
    char input, temp;
    S = CreateStack();

    cout << "Input : ";
    do
    {
        input = getchar();
        if (input != '.')
        {   
            Push(input,S);
        }
    } while (input != '.');

    while (S -> next != NULL)
    {
        temp = Top(S);
        
        switch (temp)
        {
        case '{':
            cout << temp << endl;
            count++;
            break;
        case '[':
            cout << temp << endl;
            count++;
            break;
        case '(':
            cout << temp << endl;
            count++;
            break;
        case '<':
            cout << temp << endl;
            count++;
            break;
        default:
            break;
        }
        Pop(S);
    }
    
    cout << "Open = " << count;
    return 0;
}