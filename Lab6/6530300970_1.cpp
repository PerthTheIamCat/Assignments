#include <iostream>
using namespace std;

struct record 
{
    int value;
    struct record *next;
};
struct box
{
    struct record *head;
    struct record *tail;
};

struct box enqueue(struct box q, int data)
{
    if (q.head == NULL)
    {
        q.head = new struct record;
        q.head -> value = data;
        q.head -> next = NULL;
        q.tail = q.head;
        cout << "Success!\n";
    }
    else
    {
        struct record *node;
        node = new struct record;
        node -> value = data;
        node -> next = NULL;
        q.tail -> next = node;
        q.tail = node;
        cout << "Success!\n";
    }
    return q;
}

struct box dequeue(struct box q)
{
    if (q.head != NULL)
    {
        struct record *tempCell;
        tempCell = q.head;
        q.head = q.head -> next;
        delete(tempCell); 
    }
    else
    {
        cout << "Empty! Can't Dequeue\n";
    }
    return q;
}

void menu(void)
{
    cout << "\n========MENU========\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Exit\n";
}

void printQueue(struct box q)
{
    struct record *p;
    p = q.head;
    cout << "Queue = ";
    while (p != NULL)
    {
        cout << p -> value << " ";
        p = p -> next;
    }
}
int main()
{
    struct box q;
    q.head = NULL;
    int input, data;
    do
    {
        menu();
        cout << "Please choose > ";
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "Enter data : ";
            cin >> data;
            q = enqueue(q, data);
            printQueue(q);
            break;

        case 2:
            q = dequeue(q);
            printQueue(q);
            break;

        case 3:
            cout << "OK bye!!\n";
            break;
        default:
            cout << "Invalid Input!!\n";
            break;
        }
    } while (input != 3);
    return 0;
}