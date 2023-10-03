#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// NO : 5

int main()
{
    int arr[15], x, i;
    arr[0] = 1;
    arr[1] = 1;

    cout << "Enter : ";
    cin >> x;
    
    if (x < 15)
    {
        for (i = 2; i < x; i++)
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
        cout << "Fibonaci of "<< x << " = " << arr[x-1];
    } else {
        cout << "Error, more than 15";
    }
    return 0;
}