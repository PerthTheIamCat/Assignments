#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// NO : 2

struct record
{
    int value;
    struct record *next;
};

int menu() {
    int input;

    cout << "==================MENU==================" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Print All data" << endl;
    cout << "3) Print first and last" << endl;
    cout << "4) Exit\n" << endl;
    cout << "Please choose > ";
    cin >> input;
    return input;
}

struct record *insert(struct record *head ,int data) {
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
            while (p->next != NULL)
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

void print_All(struct record *head) {
    struct record *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "Empty list!";
    } 
    else
    {
        cout << "\nList = ";
        while (temp != NULL)
        {
            cout << temp -> value << " ";
            temp = temp -> next;
        }
    }
    cout << endl;
}

void print_first_last(struct record *head) {
    struct record *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "Empty list!";
    } 
    else
    {
        cout << "\nFirst = ";
        cout << temp -> value << endl;
        temp = temp -> next;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        cout << "Last = " << temp -> value << endl;
        
    }
    cout << endl;
}

int main() {
    
    struct record *head = NULL;
    int choose, data;
    do
    {
        choose = menu();
        switch (choose)
        {
        case 1:
            cout << "Insert : ";
            cin >> data;
            head = insert(head, data);
            cout << "Success!\n";
            print_All(head);
            break;
        
        case 2:
            print_All(head);
            break;
        
        case 3:
            print_first_last(head);
            break;
        
        case 4:
            cout << "OK bye!\n";
            break;

        default:
            cout << "Invalid Number!\n" ;
            break;
        }

    } while (choose != 4);    
    return 0;
}