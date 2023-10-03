#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// HW : 3

int main() {
    
    // Declare variable
    int arr[10];
    
    // Loop for geting input in to array
    cout << "Enter : ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    // Loop for show output of array from backward
    cout << "Output : ";
    for (int i = 9; i >= 0 ; i--)
    {
        cout << arr[i] << " ";
    }
    return 0;
}