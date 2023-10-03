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
    }
    else
    {
        struct record *node;
        node = new struct record;
        node -> value = data;
        node -> next = q.head;
        q.tail -> next = node;
        q.tail = node;
    }
    return q;
}

struct box dequeue(struct box q, int M)
{
    while (q.head != q.tail)
    {
        struct record *tempCell;
        for (int i = 0; i < M; i++)
        {
            q.head = q.head -> next;
            q.tail = q.tail -> next;
        }
        tempCell = q.head;
        q.head = q.head -> next;
        q.tail -> next = q.head;
        delete(tempCell);
    }
    cout << "Winner is : " << q.head -> value << endl;
    return q;
}

int main(){
    int M,N;
    struct box q;
    q.head = NULL;
    cout << "Input M : ";
    cin >> M;
    cout << "Input N : ";
    cin >> N;
    for (int i = 1; i <= N ; i++)
    {
        q = enqueue(q, i);
    }
    q.tail -> next = q.head;
    q = dequeue(q, M);
    return 0;
}