#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// NO : 1

int main()
{
    int a[5], input, index=0, i;

    cout << "Enter : ";
    for (i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    cout << "\nOutput\n(index)| ";
    for (i = 0; i < 5; i++)
    {
        cout << i << " ";
        if (i == 3)
        {
            cout << " ";
        }
    }
    cout << "\n-------|-------------------------\n(value)| ";
    for (i = 0; i < 5; i++)
    {
        cout << a[i]<< " ";
    }
    cout << "\n\nEnter value : ";
    cin >> input;
    
    for (i = 0; i < 5; i++)
    {
        if (input > a[i])
        {
            index++;
        } else {
            break;
        }
    }
    if (index < 5)
    {
        cout << "Index = " << index << endl;
    } else {
        cout << "No number" << endl;
    }   
    return 0;
}