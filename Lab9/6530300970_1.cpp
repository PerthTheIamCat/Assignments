#include <iostream>
using namespace std;

int count_time = 0;

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

struct pathBox
{
    int pass[8];
    int d[8];
    int f[8];
    int pred[8];
    int tree = 0;
};

struct box insert(struct box recordBox, int data)
{
    struct record *head, *tail, *tmp;
    head = recordBox.head;
    tail = recordBox.tail;
    if (head == NULL)
    {
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
        tail = head;
    }
    else
    {
        tmp = new struct record;
        tmp -> value = data;
        tmp -> next = NULL;
        tail -> next = tmp;
        tail = tmp;
    }
    recordBox.head = head;
    recordBox.tail = tail;
    return recordBox;
}
void printList(struct box recordBox[])
{
    struct record *p;
    int i;
    cout << "\nADJACENCY LIST\n\n";
    for (i = 0; i < 8; i++)
    {
        p = recordBox[i].head;
        cout << "#" << i << " : ";
        while (p != NULL)
        {
            cout << p -> value << " ";
            p = p -> next;
        }
        cout << endl;
    }
}

struct pathBox DFS_Visit(struct box recordBox[], struct pathBox pathBox, int u)
{
    struct record *p;
    int v;
    pathBox.pass[u] = 1;
    pathBox.d[u] = ++count_time;
    p = recordBox[u].head;
    while (p != NULL)
    {
        v = p -> value;
        if (pathBox.pass[v] == 0)
        {
            pathBox.pred[v] = u;
            pathBox = DFS_Visit(recordBox, pathBox, v);
        }
        p = p -> next;
    }
    pathBox.pass[u] = 1;
    pathBox.f[u] = ++count_time;
    return pathBox;
}

struct pathBox DFS(struct box recordBox[], struct pathBox pathBox, int start)
{
    int u, i;
    count_time = 0;
    pathBox.tree = 0;
    for (u = 0; u < 8; u++)
    {   
        pathBox.pass[u] = 0;
        pathBox.pred[u] = -1;
        pathBox.d[u] = -1;
        pathBox.f[u] = -1;
    }
    u = start;
    pathBox = DFS_Visit(recordBox, pathBox, u);
    for (u = 0; u < 8; u++)
    {
        if (pathBox.pass[u] == 0)
        {
            pathBox = DFS_Visit(recordBox, pathBox, u);
        }
    }
    for (i = 0; i < 8; i++)
    {
        if (pathBox.pred[i] == -1)
        {
            pathBox.tree++;
        }
        
    }
    
    return pathBox;
}

void printPath(struct pathBox pathBox)
{
    int i;
    cout << "\nTree = " << pathBox.tree << endl;
    cout << "d\t:\t";
    for (i = 0; i < 8; i++)
    {
        cout << pathBox.d[i] << "\t";
    }
    cout << endl;
    cout << "f\t:\t";
    for (i = 0; i < 8; i++)
    {
        cout << pathBox.f[i] << "\t";
    }
    cout << endl;
    cout << "pred\t:\t";
    for (i = 0; i < 8; i++)
    {
        cout << pathBox.pred[i] << "\t";
    }
    cout << endl;
}

int menu(void)
{
    int choose;
    cout << "=============MENU=============\n";
    cout << "1) Insert Graph\n";
    cout << "2) DFS\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

int main()
{
    struct box adj[8];
    struct pathBox pathBox;
    int choose, i, data;

    for (i = 0; i < 8; i++)
    {
        adj[i].head = NULL;
        adj[i].tail = NULL;
    }
    do
    {
        choose = menu();
        switch (choose)
        {
        case 1:
            if (adj[0].head != NULL)
            {
                cout << "Already Insert!!! Please Exit and Start again\n";
                printList(adj);
                break;
            }
            for (i = 0; i < 8; i++)
            {
                cout << "#" << i << " : ";
                do
                {
                    cin >> data;
                    if (data != -1)
                    {
                        adj[i] = insert(adj[i], data);
                    }
                } while (data != -1);
            }
            cout << "Insert Complete!!\n";
            printList(adj);
            break;
        
        case 2:
            cout << "Input source vertex : ";
            cin >> data;
            pathBox = DFS(adj, pathBox, data);
            printPath(pathBox);
            break;
        
        case 3:
            cout << "Ok bye!!\n";
            break;
        
        default:
            cout << "Invalid Input !!! please try again\n";
            break;
        }
    } while (choose != 3);
    
    return 0;
}