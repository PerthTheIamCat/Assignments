#include <iostream>
using namespace std;

// Written By Pawit Thongkum
// ID : 6530300970
// NO : 1

struct record 
{
    int value;
    int pow;
    struct record *next;
};

int countTerm(struct record *head)
{
    struct record *p;
    int count = 0;
    p = head;
    while (p -> next != NULL)
    {
        count++;
        p = p -> next;
    }
    return count;
}

struct record *insert(struct record *head, int data, int power)
{
    struct record *p, *node;
    
    if (head == NULL)
    {
        head = new struct record;
        head -> value = data;
        head -> pow = power;
        head -> next = NULL;
    }
    else
    {
        node = new struct record;
        node -> value = data;
        node -> pow = power;
        node -> next = NULL;
        
        p = head;
        while (p != NULL)
        {
            if (node -> pow > p -> pow)
            {
                node -> next = p;
                head = node;
                break;
            }
            else
            {
                if (node -> pow == p -> pow)
                {
                    p -> value += node -> value;
                    break;
                }
                else
                {
                    if (p -> next == NULL)
                    {
                        p -> next = node;
                        break;
                    }
                    else
                    {
                        p = p -> next;
                    }
                }
            }
            
        }
    }
    return head;
}

void printAll(struct record *head)
{
    struct record *p;
    cout << "Longer : ";
    
    p = head;
    while (p != NULL)
    {
        
        if (p -> pow == 1)
        {
            cout << p -> value << "x";
        }
        else
        {
            if (p -> pow == 0)
            {
                cout << p -> value;
            }
            else
            {
                cout << p -> value << "x^" << p -> pow;
            }
            
        }
        if (p -> next != NULL)
        {
            cout << " + ";
        }
        p = p -> next;
    }
}

int main() 
{
    struct record *head = NULL;
    int data, pow;

    cout << "Input P1 : ";
    do
    {
        cin >> data;
        
        if (data != -99)
        {
            cin >> pow;
            head = insert(head, data, pow);
        }
    } while (data != -99);

    data = 0;
    cout << "Input P2 : ";
    do
    {
        cin >> data;
        
        if (data != -99)
        {
            cin >> pow;
            head = insert(head, data, pow);
        }
    } while (data != -99);

    printAll(head);
    return 0;
}