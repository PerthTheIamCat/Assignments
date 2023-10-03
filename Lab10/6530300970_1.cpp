#include <iostream>
using namespace std;

int a[30];
int heapsize = 0;
int length = sizeof(a) / sizeof(a[0]);

int menu(void)
{
    int choose;
    cout << "===========MENU===========\n";
    cout << "1) Insert data to array\n";
    cout << "2) Build Heap\n";
    cout << "3) Heap Sort\n";
    cout << "4) Heap insert\n";
    cout << "5) Priority Queue\n";
    cout << "6) Extract Max\n";
    cout << "7) Exit\n";
    cout << "\n\tPlease choose > ";
    cin >> choose;
    return choose;
}

void insertArray(int array[],int value, int i)
{
    array[i] = value;
}

int parent(int i)
{
	return i/2;
}

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i+1;
}

void heapify(int a[], int i)
{
    int largest;
    int l = left(i);
    int r = right(i);
    if (l <= heapsize && a[l] > a[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= heapsize && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(a[i],a[largest]);
        heapify(a, largest);
    }
}

void build_heap(int a[])
{
    length = heapsize;
    for (int i = length/2; i >= 1; i--)
    {
        heapify(a, i);
    }
}

void heapsort(int a[])
{
    build_heap(a);
    int tmp = heapsize;
    for (int i = heapsize; i >= 2; i--)
    {
        swap(a[1], a[i]);
        heapsize--;
        heapify(a, 1);
    }
    heapsize = tmp;
}

void heap_insert(int a[], int data)
{
    heapsize++;
    int i = heapsize;
    while (i > 1 && a[parent(i)] < data)
    {
        a[i] = a[parent(i)];
        i = parent(i);
        a[i] = data;
    }   
}

void printArray(int a[])
{
    for (int i = 1; i <= heapsize; i++)
    {
        cout << a[i] << " ";
    }
}

void extractMax(int a[])
{
    int max;
    max = a[1];
	a[1] = a[heapsize];
	heapsize--;
	heapify(a,1);
	cout << "Max = " << max << endl;
}

int main()
{
    string tmp, data;
    int choose, i, size;
    int index = 1;
    do
    {
        choose = menu();
        switch (choose)
        {
        case 1:
            getchar();          // flush
            cout << "Input : "; // 4 1 3 2 16 9 10 14 8 7
            getline(cin, tmp);
            size = tmp.size();
            for (i = 0; i <= size; i++)
            {
                if (tmp[i] == ' ')
                {
                    insertArray(a, stoi(data), index);
                    heapsize++;
                    index++;
                    data = "";
                }
                else
                {
                    data += tmp[i];
                    if (i == size)
                    {
                    insertArray(a, stoi(data), index);
                    heapsize++;
                    data = "";
                    index++;
                    }
                }
            }
            break;
        
        case 2:
            build_heap(a);
            cout << "Heap : ";
            printArray(a);
            cout << endl;
            break;
        
        case 3:
            heapsort(a);
            cout << "Heap Sort : ";
            printArray(a);
            cout << endl;
            break;
        
        case 4:
            build_heap(a);
            cout << "insert : ";
            cin >> data;
            insertArray(a, stoi(data), heapsize);
            cout << "Array : ";
            printArray(a);
            cout << endl;
            build_heap(a);
            cout << "Heap : ";
            printArray(a);
            cout << endl;
            break;
        
        case 5:
            cout << "Priority Queue Heap : ";
            printArray(a);
            cout << endl;
            break;
        
        case 6:
            extractMax(a);
            cout << "Heap : ";
            printArray(a);
            cout << endl;
            break;
        
        case 7:
            cout << "Ok bye !!\n";
            break;
        
        default:
            cout << "Invalid input !!! please try again\n";
            break;
        }
    } while (choose != 7);
    
    return 0;
}