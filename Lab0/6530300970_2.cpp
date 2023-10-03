#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// HW : 2

int main() {
    
    // Declare variable
    int input;
    int i = 2;

    // Get input
    cout << "Input : ";
    cin >> input;

    // Loop checking for prime number
    if (input < 2)
    {
        cout << "Not prime" << endl;
    } else {
        while (i <= input-1)
        {
            if (input % i == 0)
            {
                cout << "Not prime" << endl;
                return 0;
            } else {
                i++;
            }
        }
        cout << "Prime" << endl;
    }
    return 0;
}