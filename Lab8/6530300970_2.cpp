#include <iostream>
using namespace std;

struct record
{
    int value;
    struct record *next;
};

struct record *insert(struct record *head, int data)
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

int menu(void)
{
    int choose;
    cout << "==============MENU==============\n";
    cout << "1) Input adjacency list\n";
    cout << "2) Input adjacency matrux\n";
    cout << "3) Show self loop from adjacency list\n";
    cout << "4) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    cout << endl;

    return choose;
}

void printList(struct record *adj[])
{
    struct record *p;
    int i;
    cout << "ADJACENCY LIST\n\n";
    for (i = 0; i < 6; i++)
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

void printMatrix(int matrix[][6])
{
    int i, j;

    cout << "ADJACENCY MATRIX\n\n";
    cout << "-----------------------\n\n";
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl << endl;
    }
    cout << endl;
}

void find_selfloop(struct record *adj[])
{
    struct record *p;
    int i;
    cout << "Selfloop : ";
    for (i = 0; i < 6; i++)
    {
        p = adj[i];
        while (p != NULL)
        {
            if (p -> value == i)
            {
                cout << i << " ";
            }
            p = p -> next;
        }
    }
    cout << endl << endl;
}

int main()
{
    struct record *adj[6], *p;
    int matrix[6][6];
    int i, j, choose, data;
    for (i = 0; i < 6; i++)
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
            for (i = 0; i < 6; i++)
            {
                cout << "Enter #" << i << " : ";
                do
                {
                    cin >> data;
                    if (data != -1)
                    {
                        adj[i] = insert(adj[i], data);
                    }
                } while (data != -1);
            }
            printList(adj);
            break;
        
        case 2:
            if (adj[0] != NULL)
            {
                cout << "Already Insert!!!\n";
                for (i = 0; i < 6; i++)
                {
                    p = adj[i];
                    while (p != NULL)
                    {
                       for (j = 0; j < 6; j++)
                        {
                            if (p -> value == j)
                            {
                                matrix[i][j] = 1;
                            }
                            else
                            {
                                if (matrix[i][j] == 1)
                                {
                                    continue;
                                }
                                matrix[i][j] = 0;
                            }
                        }
                        p = p -> next;
                    }
                }
                printMatrix(matrix);
                break;
            }
            for (i = 0; i < 6; i++)
            {
                cout << "Enter #" << i << " : ";
                do
                {
                    cin >> data;
                    if (data != -1)
                    {
                        adj[i] = insert(adj[i], data);
                    }
                } while (data != -1);
            }
            for (i = 0; i < 6; i++)
            {
                p = adj[i];
                while (p != NULL)
                {
                    for (j = 0; j < 6; j++)
                    {
                        if (p -> value == j)
                        {
                            matrix[i][j] = 1;
                        }
                        else
                        {
                            if (matrix[i][j] == 1)
                            {
                                continue;
                            }
                            matrix[i][j] = 0;
                        }
                    }
                    p = p -> next;
                }
            }
            
            printMatrix(matrix);
            break;

        case 3:
            find_selfloop(adj);
            
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
