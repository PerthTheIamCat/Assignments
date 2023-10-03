#include <iostream>
using namespace std;

// Writen By Pawit Thongkum
// ID : 6530300970
// Ex : 1

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
    cout << "2) Delete\n";
    cout << "3) Print min to max / max to min\n";
    cout << "4) Count node\n";
    cout << "5) Print only odd node\n";
    cout << "6) Exit\n";
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

struct record *deleteValue(struct record *head, int data)
{
    struct record *p, *tempfree;
    p = head;
    if (p -> value == data)
    {
        tempfree = p;
        head = p -> next;
        head -> prev = NULL;
        delete(tempfree);
        return head;
    }
    
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    if (data == p -> value)
    {
        tempfree = p;
        p -> prev -> next = NULL;
        delete(tempfree);
        return head;
    }

    p = head;
    while (p -> next != NULL)
    {
        if (p -> next -> value == data)
        {   
            tempfree = p -> next;
            p -> next = p -> next -> next;
            p -> next -> prev = p;
            delete(tempfree);
            break;
        }
        else 
        {
            p = p -> next;
        }
    }
    return head;
}

int countNode(struct record *head)
{
    struct record *p;
    int count = 0;

    p = head;
    while (p != NULL)
    {
        count++;
        p = p -> next;
    }
    return count;
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
    cout << endl;
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

void printOnlyOddNode(struct record *head)
{
    struct record *temp;

    temp = head;
    cout << "Odd node = ";
    while (temp != NULL)
    {
        cout << temp -> value << " ";
        if (temp -> next != NULL)
        {
            temp = temp -> next -> next;
        }
        else
        {
            break;
        }
    }
    cout << endl;
}

int main() 
{
    struct record *head = NULL;
    int input, data;
    while (input != 6)
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
            cout << "Delete : ";
            cin >> data;
            cout << "Success!\n";
            head = deleteValue(head, data);
            break;
        case 3:
            printMinToMax_MaxToMin(head);
            break;
        case 4:
            cout << "Number of node = "<< countNode(head) << endl;
            break;
        case 5:
            printOnlyOddNode(head);
            break;
        case 6:
            cout << "OK bye!\n";

            break;
        default:
            cout << "Invalid Input\n";
            break;
        }
    }
    
    return 0;
}