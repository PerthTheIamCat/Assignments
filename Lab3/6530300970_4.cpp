#include <iostream>
using namespace std;

// Writen By Pawit Thongkum
// ID : 6530300970
// Ex : 4

struct record
{
    int value;
    struct record *next;
    struct record *prev;
};

int menu()
{
    int input;
    cout << "================MENU================\n";
    cout << "1) Insert\n";
    cout << "2) Print min to max / max to min\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> input;
    return input;
}

struct record *insert(struct record *head,int data)
{
    struct record *node, *p;

    if (head == NULL)
    {
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
        head -> prev = NULL;
    }
    else
    {
        node = new struct record;
        node -> value = data;
        if (data < head -> value)
        {
            node -> next = head;
            node -> prev = NULL;
            head -> prev = node;
            head = node;
        }
        else
        {
            p = head;
            while (p -> next != NULL)
            {
                if (data < p -> next -> value)
                {
                    node -> next = p -> next;
                    node -> prev = p;
                    p -> next -> prev = node;
                    p -> next = node;
                    break;
                }
                else
                {
                    p = p -> next;
                }
            }
            if (p -> next == NULL)
            {
                node -> next = NULL;
                node -> prev = p;
                p -> next = node;
            }
        }
    }
    return head;
}

void printMinToMax_MaxToMin(struct record *head)
{
    struct record *temp;

    temp = head;

    cout << "Min to max : ";
    while (temp != NULL)
    {
        cout << temp -> value << " ";
        temp = temp -> next;
    }
    cout << endl << endl;
    cout << "Max to min : ";
    temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    while (temp != NULL)
    {
        cout << temp -> value << " ";
        temp = temp -> prev;
    }
    cout << endl;
}

int main()
{
    struct record *head = NULL;
    int input, data;

    while (input != 3)
    {
        input = menu();
        switch (input)
        {
        case 1:
            cout << "Insert : ";
            cin >> data;

            head = insert(head, data);
            break;
        case 2:
            printMinToMax_MaxToMin(head);
            break;

        case 3:
            cout << "OK bye!\n";

            break;
        default:
            break;
        }

    }
    
    return 0;
}