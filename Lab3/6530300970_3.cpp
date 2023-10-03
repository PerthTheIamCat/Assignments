#include <iostream>
using namespace std;

// Writen By Pawit Thongkum
// ID : 6530300970
// Ex : 3

struct record 
{
    int value;
    struct record *next;
};

int countTerm(struct record *head)
{
    struct record *p;
    int count = 0;
    p = head;
    while (p -> next -> next != NULL)
    {
        count++;
        p = p -> next -> next;
    }
    return count;
}

struct record *insert(struct record *head, int data)
{
    struct record *node, *p;

    if (head == NULL)
    {
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
    }
    else
    {
        node = new struct record;
        node -> value = data;
        node -> next = NULL;
        p = head;
        while (p != NULL)
        {
            if (p -> next == NULL)
            {
                p -> next = node;
                break;
            }
            p = p -> next;
        }
    }
    return head;
}

void printLonger(struct record *head)
{
    struct record *p;
    cout << "Longer : ";
    
    p = head;
    while (p != NULL)
    {
        
        if (p -> next -> value == 1)
        {
            cout << p -> value << "x";
        }
        else
        {
            if (p -> next -> value == 0)
            {
                cout << p -> value;
            }
            else
            {
                cout << p -> value << "x^" << p -> next -> value;
            }
            
        }
        if (p -> next -> next != NULL)
        {
            cout << " + ";
        }
        p = p -> next -> next;
    }
}

int main() 
{
    struct record *headP1 = NULL;
    struct record *headP2 = NULL;
    int i, input;
    cout << "Input P1 : ";
    do
    {
        cin >> input;
        if (input != -99)
        {
            headP1 = insert(headP1, input);
        }
        
    } while (input != -99);

    input = 0;
    cout << "Input P2 : ";
    do
    {
        cin >> input;
        if (input != -99)
        {
            headP2 = insert(headP2, input);
        }
        
    } while (input != -99);
    
    if (countTerm(headP1) > countTerm(headP2))
    {
        printLonger(headP1);
    }
    else
    {
        printLonger(headP2);
    }
    return 0;
}