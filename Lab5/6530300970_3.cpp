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
        cout << "Empty Stack!!!\n";
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

int main()
{
    Stack S;
    S = CreateStack();
    string input, symbol;
    int x, y, output;
    
    cout << "Input : ";
    do
    {
        cin >> input;
        if (input != ".")
        {
            Push(input, S);
        }
    } while (input != ".");
    
    y = stoi(Top(S));
    Pop(S);
    symbol = Top(S);
    Pop(S);
    x = stoi(Top(S));
    Pop(S);
    if (symbol == "+")
    {   
        output = x + y;
    }
    cout << x << "\t" << "digit" << endl;
    cout << symbol <<"\t" << "symbol" << endl;
    cout << y << "\t" << "digit" << endl;
        
    cout << "Output = " << output << endl;

    return 0;
}