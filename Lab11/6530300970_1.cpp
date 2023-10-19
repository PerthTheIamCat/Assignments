#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

struct record
{
    int value;
    struct record *next;
};

int dataSize = 2000000;      // Size of data 
int dataRange = 10000;      // Range of data (100 : 0 - 99) (10000 : 0 - 9999)

int *A = new int[dataSize];
int heapsize = 0;
int length = sizeof(A) / sizeof(A[0]);;

void showProgressBar(int i, int max)
{
    cout << "\033[K"; // ลบทั้งบรรทัด
    int percent = (i * 100) / max;
    cout << "Sorting " << percent << " % [ " << i << " / " << dataSize << " ]\r";
    cout.flush();
}

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

int menu(void)
{
    int choose;
    cout << "============MENU============\n";
    cout << "1) Create data file\n";
    cout << "2) Selection\tSort\n";
    cout << "3) Bubble\tSort\n";
    cout << "4) Insertion\tSort\n";
    cout << "5) Shell\tSort\n";
    cout << "6) Merge\tSort\n";
    cout << "7) Quick\tSort\n";
    cout << "8) Radix\tSort\n";
    cout << "9) Heap\t\tSort\n";
    cout << "10) Exit\n\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose; 
}

void read_file(string file_name)
{
    ifstream readfile (file_name);
    int number;
    readfile.is_open();
    cout << "Data in flie >> ";
    for (int i = 0; i < dataSize; i++)
    {
        readfile >> number;
        cout << number << " ";
    }
    readfile.close();
    cout << endl;
}

void create_file(void)
{ 
    ofstream myfile ("randomNumber.txt");
    if (myfile.is_open())
    {
        srand(time(0));
        for (int i = 0; i < dataSize; i++)
        {
            myfile << rand() % dataRange << " ";
        }
        cout << "\nSuccess\n";
    }
    else
    {
        cout << "\nUnable to open file\n";
    }
    myfile.close();
    //read_file("randomNumber.txt");
}

int findMin(int arr[], int start, int stop) {
    int min = arr[start];
    for (int i = start; i < stop; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void selection_sort()
{
    ifstream readfile ("randomNumber.txt");
    int number, min;
    int *a = new int[dataSize];
    int i, n;

    readfile.is_open();
    for (i = 0; i < dataSize; i++)
    {
        readfile >> number;
        a[i] = number;
    }
    readfile.close();

    for (n = 0; n < dataSize; n++)
    {
        showProgressBar(n, dataSize);
        for (i = n; i < dataSize; i++)
        {
            showProgressBar(i, dataSize);
            min = findMin(a, n, dataSize);
            if (a[i] == min)
            {
                swap(a[i], a[n]);
            }
        }
    }

    ofstream myfile ("Selection.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < dataSize; i++)
        {
            myfile << a[i] << " ";
        }
        cout << "\nSuccess\n";
    }
    else
    {
        cout << "\nUnable to open file\n";
    }
    myfile.close();
    //read_file("Selection.txt");
}

void bubble_sort()
{
    int i, j, number;
    int *a = new int[dataSize];
    ifstream readfile ("randomNumber.txt");
    readfile.is_open();
    for (i = 0; i < dataSize; i++)
    {
        readfile >> number;
        a[i] = number;
    }
    readfile.close();

    for (i = 0; i < dataSize-1; i++)
    {
        showProgressBar(i, dataSize);
        for (j = dataSize-1; j >= i; j--)
        {
            if (a[j] < a[j-1] && j-1 >= 0)
            {
                swap(a[j], a[j-1]);
            }
        }
    }
    
    ofstream myfile ("Bubble.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < dataSize; i++)
        {
            myfile << a[i] << " ";
        }
        cout << "\nSuccess\n";
    }
    else
    {
        cout << "\nUnable to open file\n";
    }
    myfile.close();
    //read_file("Bubble.txt");
}

void insertion_sort()
{
    int i, j, number, tmp;
    int *a = new int[dataSize];
    ifstream readfile ("randomNumber.txt");
    readfile.is_open();
    for (i = 0; i < dataSize; i++)
    {
        readfile >> number;
        a[i] = number;
    }
    readfile.close();

    for (i = 1; i < dataSize; i++)
    {
        showProgressBar(i, dataSize);
        tmp = a[i];
        for ( j = i; j > 0 && a[j-1] > tmp; j--)
        {
            a[j]=a[j-1];
        }
        a[j] = tmp;
    }
    
    ofstream myfile ("Insertion.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < dataSize; i++)
        {
            myfile << a[i] << " ";
        }
        cout << "\nSuccess\n";
    }
    else
    {
        cout << "\nUnable to open file\n";
    }
    myfile.close();
    //read_file("Insertion.txt");
}

void shell_sort()
{
    int i, j, number;
    int *a = new int[dataSize];
    ifstream readfile ("randomNumber.txt");
    readfile.is_open();
    for (i = 0; i < dataSize; i++)
    {
        readfile >> number;
        a[i] = number;
    }
    readfile.close();

    for (int gap = dataSize / 2; gap > 0; gap /= 2) 
    {
        showProgressBar(gap, dataSize);
        for (i = gap; i < dataSize; i++) 
        {
            showProgressBar(i, dataSize);
            int temp = a[i];
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) 
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
    
    ofstream myfile ("Shellsort.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < dataSize; i++)
        {
            myfile << a[i] << " ";
        }
        cout << "\nSuccess\n";
    }
    else
    {
        cout << "\nUnable to open file\n";
    }
    myfile.close();
    //read_file("Shellsort.txt");
}

void merge(int a[],int tmp[], int lpos, int rpos, int rightend)
{
    int i, leftend, numelements, tmppos;
    leftend = rpos -1;
    tmppos = lpos;
    numelements = rightend - lpos + 1;

    while (lpos <= leftend && rpos <= rightend)
    {
        if (a[lpos] <= a[rpos])
        {
            tmp[tmppos++] = a[lpos++];
        }
        else
        {
            tmp[tmppos++] = a[rpos++];
        }
    }
    while (lpos <= leftend)
    {
        tmp[tmppos++] = a[lpos++];
    }
    while (rpos <= rightend)
    {
        tmp[tmppos++] = a[rpos++];
    }
    for (i = 0; i < numelements; i++, rightend--)
    {
        a[rightend] = tmp[rightend];
    }
}

void merge_sort(int a[], int tmp[], int left, int right)
{
    int center;
    if (left < right)
    {
        center = (left + right) / 2;
        merge_sort(a,tmp,left, center);
        merge_sort(a,tmp,center + 1, right);
        merge(a, tmp, left, center + 1, right);
    }
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) 
    {
        showProgressBar(j, high);
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quick_sort()
{
    int i, number;
    int *a = new int[dataSize];
    ifstream readfile ("randomNumber.txt");
    readfile.is_open();
    for (i = 0; i < dataSize; i++)
    {
        readfile >> number;
        a[i] = number;
    }
    readfile.close();

    quickSort(a, 0, dataSize - 1);

    ofstream myfile ("QuickSort.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < dataSize; i++)
        {
            myfile << a[i] << " ";
        }
        cout << "\nSuccess\n";
    }
    else
    {
        cout << "\nUnable to open file\n";
    }
    myfile.close();
    //read_file("QuickSort.txt");
}

void radix_sort()
{
    int unit[] = {10, 100, 1000};
    int unit2[] = {1, 10, 100};
    int i, number;
    int *a = new int[dataSize];
    ifstream readfile ("randomNumber.txt");
    readfile.is_open();
    for (i = 0; i < dataSize; i++)
    {
        readfile >> number;
        a[i] = number;
    }
    readfile.close();

    for (int k = 0; k < 3; k++)
    {
        struct record *radix[10], *p;
        for (i = 0; i < 10; i++)
        {
            radix[i] = NULL;
        }

        for (i = 0; i <= 9; i++)
        {
            showProgressBar(i, 9);
            for (int j = 0; j < dataSize; j++)
            {
                showProgressBar(j, dataSize);
                if ((a[j] % unit[k]) / unit2[k] == i)
                {
                    radix[i] = insert(radix[i], a[j]);
                }
            }
        }
        int j = 0;
        for (i = 0; i < 9; i++)
        {
            p = radix[i];
            while (p != NULL)
            {
                a[j] = p -> value;
                j++;
                p = p -> next;
            }
        }
    }
    
    ofstream myfile ("RadixSort.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < dataSize; i++)
        {
            myfile << a[i] << " ";
        }
        cout << "\nSuccess\n";
    }
    else
    {
        cout << "\nUnable to open file\n";
    }
    myfile.close();
    //read_file("RadixSort.txt");
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
        showProgressBar(i, heapsize);
        swap(a[1], a[i]);
        heapsize--;
        heapify(a, 1);
    }
    heapsize = tmp;
}

int main()
{
    ifstream readfile ("randomNumber.txt");
    ofstream myfile ("MergeSort.txt");
    ofstream Heapfile ("HeapSort.txt");
    int i, number;
    int *a = new int[dataSize];
    int *tmp = new int[dataSize];
    int input;
    do
    {
        input = menu();
        
        switch (input)
        {
        case 1:
            create_file();
            break;
        
        case 2:
            selection_sort();
            break;
        
        case 3:
            bubble_sort();
            break;
        
        case 4:
            insertion_sort();
            break;
        
        case 5:
            shell_sort();
            break;
        
        case 6:
            readfile.is_open();
            for (i = 0; i < dataSize; i++)
            {
                readfile >> number;
                a[i] = number;
            }
            readfile.close();
            merge_sort(a, tmp,0, dataSize-1);

            if (myfile.is_open())
            {
                for (i = 0; i < dataSize; i++)
                {
                    myfile << a[i] << " ";
                }
                cout << "\nSuccess\n";
            }
            else
            {
                cout << "\nUnable to open file\n";
            }
            myfile.close();
            //read_file("MergeSort.txt");
            break;
        
        case 7:
            quick_sort();
            break;
        
        case 8:
            radix_sort();
            break;
        
        case 9:
            readfile.open("randomNumber.txt");
            readfile.is_open();
            for (i = 0; i < dataSize; i++)
            {
                readfile >> number;
                A[i] = number;
                heapsize++;
            }
            readfile.close();
            
            build_heap(A);

            heapsort(A);

            if (Heapfile.is_open())
            {
                for (i = 0; i < dataSize; i++)
                {
                    Heapfile << A[i] << " ";
                }
                cout << "\nSuccess\n";
            }
            else
            {
                cout << "\nUnable to open file\n";
            }
            Heapfile.close();
            //read_file("HeapSort.txt");
            break;
        
        case 10:
            cout << "\nOk, Goodbye!\n\n";
            break;
        default:
            cout << "\nInvalid input! Please Try again!!\n\n";
            break;
        }
    } while (input != 10);
    

    return 0;
}