#include <iostream>
using namespace std;

struct record
{
    int value;
    struct record *next;
};

int menu(void)
{
    int choose;
    cout << "==============MENU==============\n";
    cout << "1) Input adjacency list\n";
    cout << "2) BFS\n";
    cout << "3) Search path\n";
    cout << "4) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    cout << endl;

    return choose;
}

struct record *insert_last(struct record *head, int data)
{

    if (head == NULL)
    {
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
    }
    else 
    {
        struct record *node, *p;
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

struct record *insert_front(struct record *head, int data)
{

    if (head == NULL)
    {
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
    }
    else 
    {
        struct record *node, *p;
        node = new struct record;
        node -> value = data;
        node -> next = head;
        head = node;
    }
    return head;
}

struct record *enqueue(struct record *head, int data)
{
    head = insert_last(head, data);
    return head;
}

struct record *dequeue(struct record *head)
{
    struct record *tmp;
    tmp = head;
    head = head -> next;
    delete(tmp);

    return head;
}
int queuesize(struct record *head)
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

void printList(struct record *adj[])
{
    struct record *p;
    int i;
    cout << "\nADJACENCY LIST\n\n";
    for (i = 0; i < 8; i++)
    {
        p = adj[i];
        cout << "#" << i << " : " ;
        while (p != NULL)
        {
            cout << p -> value << " ";
            p = p -> next;
        }
        cout << endl;
    }
    cout << endl;
}

struct record *find_path(int pred[], int destination)
{
    struct record *path = NULL;
    int tmp = destination;
    path = insert_front(path, destination);
    while (pred[tmp] != 2)
    {
        path = insert_front(path, pred[tmp]);
        tmp = pred[tmp];
    }
    path = insert_front(path, pred[tmp]);
    return path;
}

int main()
{
    struct record *adj[8], *queue = NULL, *node = NULL, *path = NULL, *p;
    int choose, data, i, pass[8], d[8], pred[8], distance = 0;
    int u, v;
    for (i = 0; i < 8; i++)
    {
        adj[i] = NULL;
    }
    do
    {
        choose = menu();
        switch (choose)
        {
        case 1:
            if (adj[0] != NULL)
            {
                cout << "Already Insert!!!\n";
                printList(adj);
                break;
            }
            for (i = 0; i < 8; i++)
            {
                cout << "Enter #" << i << " : ";
                do
                {
                    cin >> data;
                    if (data != -1)
                    {
                        adj[i] = insert_last(adj[i], data);
                    }
                } while (data != -1);
            }
            printList(adj);
            break;
        
        case 2:
            for (i = 0; i < 8; i++)
            {
                pass[i] = 0;
                d[i] = -1;
                pred[i] = -1;
            }
            pass[2] = 1;
            d[2] = 0;
            pred[2] = 2;
            queue = enqueue(queue, 2);

            while (queuesize(queue) != 0)
            {
                u = queue -> value;
                node = adj[u];
                while (node != NULL)
                {
                    v = node -> value;
                    if (pass[v] == 0)
                    {
                        pass[v] = 1;
                        d[v] = d[u] + 1;
                        pred[v] = u;
                        queue = enqueue(queue, v);
                    }
                    node = node -> next;
                }
                queue = dequeue(queue);
            }
            
            cout << "   |  d  | pred\n==================\n";
            for (i = 0; i < 8; i++)
            {
                cout << i << "  |  " << d[i] << "  |  " << pred[i] << endl;
            }
            cout << endl;
            break;
        
        case 3:
            distance = 0;
            cout << "Enter end point : ";
            cin >> data;
            path = find_path(pred, data);
            p = path;
            cout << "\nPath = ";
            
            while (p -> next != NULL)
            {
                cout << "("<<p -> value<< "," << p -> next -> value << ")";
                distance++;
                if (p -> next -> next != NULL)
                {
                    cout << " , ";
                }
                p = p -> next;
            }
            cout << endl;
            cout << "Distance = " << distance << endl << endl;
            break;
        
        case 4:
            cout << "Ok bye!!\n";
            break;
        
        default:
            cout << "Invalid Input!!!\n";
            break;
        }
    } while (choose != 4);
    
    return 0;
}