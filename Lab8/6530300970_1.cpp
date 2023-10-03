#include <iostream>
using namespace std;

struct record
{
    int value;
    struct record *next;
};

struct box{
    struct record *head = NULL;
    struct record *end = NULL;
};

struct box insert(struct box box, int data)
{

    if (box.head == NULL)
    {
        box.head = new struct record;
        box.head -> value = data;
        box.head -> next = NULL;
        box.end = box.head;
    }
    else 
    {
        struct record *node;
        node = new struct record;
        node -> value = data;
        node -> next = NULL;
        box.end -> next = node;
        box.end = node;
    }
    return box;
}

void printList(struct box box)
{
    struct record *p;
    p = box.head;
    while (p != NULL)
    {
        cout << p -> value << " ";
        p = p -> next;
    }
}

int main()
{
    struct box box;
    int data;

    cout << "Input : ";
    do
    {
        cin >> data;
        if (data != -1)
        {
            box = insert(box, data);
        }
    } while (data != -1);
    
    cout << "List : ";
    printList(box);

    return 0;
}