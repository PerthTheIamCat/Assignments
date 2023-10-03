#include <iostream>
using namespace std;

// Writen By Pawit Thongkum
// ID : 6530300970
// Ex : 2

struct record
{
    char value;
    struct record *next;
};

int menu()
{
    int input;
    cout << "================MENU================\n";
    cout << "1) Insert\n";
    cout << "2) Decode\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> input;

    return input;
}

struct record *insert(struct record *head, char data)
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

void printList(struct record *head)
{
    struct record *temp;

    temp = head;

    cout << "List : ";
    while (temp != NULL)
    {
        cout << temp -> value;
        temp = temp -> next;
    }
    cout << endl << endl;
}

void printDecode(struct record *head)
{
    struct record *temp;

    temp = head;

    cout << "Decode : ";
    while (temp != NULL)
    {
        cout << temp -> value;
        temp = temp -> next -> next;
    }
    cout << endl << endl;
}

int main()
{
    struct record *head = NULL;
    int input;
    char data;

    while (input != 3)
    {
        input = menu();
    
        switch (input)
        {
        case 1:
            getchar();
            cout << "Insert : ";
            do
            {
                data = getchar();
                if (data == '.')
                {
                    continue;
                }
                else
                {
                    head = insert(head, data);
                }
            } while (data != '.');
            printList(head);
            break;

        case 2:
            printDecode(head);
            break;

        case 3:
            cout << "Good bye!\n";
            break;
        
        default:
            cout << "Invalid Input\n";
            break;
        }
    }   
    return 0;
}