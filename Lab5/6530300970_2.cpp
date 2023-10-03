#include <iostream>
using namespace std;

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

char Top(Stack S)
{
    if (!IsEmpty(S))
    {
        return S -> next -> value;
    }
    else 
    {
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
    char input, tempNow = ' ', tempPrev = ' ';
    S = CreateStack();

    cout << "Input : ";
    do
    {
        input = getchar();
        if (input != '.')
        {
            Push(input, S);
        }
    } while (input != '.');

    tempNow = Top(S);
    
    
    while (S -> next != NULL)
    {
        if (tempNow != '}' && tempPrev == ' ')
        {
            cout << "Expected }";
            break;
        }
        if (tempNow == '}' || tempNow == ']' || tempNow == ')' || tempNow == '>')
        {
            tempPrev = tempNow;
            Pop(S);
            tempNow = Top(S);
            continue;
        }
        else 
        {
            if (tempNow == '{' && tempPrev != '}')
            {
                cout << "Expected }";
                break;
            }
            else
            {
                if (tempNow == '[' && tempPrev != ']')
                {
                    cout << "Expected ]";
                    break;
                }
                else
                {
                    if (tempNow == '(' && tempPrev != ')')
                    {
                        cout << "Expected )";
                        break;
                    }
                    else
                    {
                        if (tempNow == '<' && tempPrev != '>')
                        {
                            cout << "Expected >";
                            break;
                        }
                        else 
                        {
                            Pop(S);
                        }
                    }
                }
            }
        }
    }
    if (S -> next == NULL)
    {
        cout << "Complete!";
    }
    return 0;
}