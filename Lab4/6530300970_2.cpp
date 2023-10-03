#include <iostream>
using namespace std;

// Written By Pawit Thongkum
// ID : 6530300970
// NO : 2

struct record
{
    int value;
    struct record *next;
};

int menu(void)
{
    int input;
    cout << "===========MENU===========\n";
    cout << "1) Insert\n";
    cout << "2) Delete\n";
    cout << "3) Print\n";
    cout << "4) Exit\n";
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
    }
    else
    {
        node = new struct record;
        node -> value = data;
        if (data < head -> value)
        {
            node -> next = head;
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

void printAll(struct record *head)
{
    struct record *temp;

    temp = head;

    cout << "List : ";
    while (temp != NULL)
    {
        cout << temp -> value << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    struct record *head = NULL;
    int input, data;
    while (input != 4)
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
            cout << "\nSuccess!\n";
            head = deleteValue(head, data);
            break;
        
        case 3:
            printAll(head);
            break;
        
        case 4:
            cout << "OK bye!\n";
            break;
        default:
            cout << "Invalid Input\n";
            break;
        }
    }
    

    return 0;
}