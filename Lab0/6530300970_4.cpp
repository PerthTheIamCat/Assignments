#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// HW : 4

int main() {   

    // Declare variable
    int input;

    // Get input
    cout << "Input : ";
    cin >> input;

    /* Loop for show pyramid number sequence from inputted number */
    // loop 1 : for changing line
    for (int i = 1; i <= input; i++)
    {
        cout << i << " ";
        // loop 2 : for set the amount that want to print in each time
        for (int j = i+1; j <= input; j++)
        {
            // loop 3 : for printing a number
            for (int k = i; k <= j; k++)
            {
                cout << k;
            }
            cout << " ";
        }
        // special case for the last number that did not print correctly
        if (i == input)
        {
           cout << i;
        }
        cout << endl;
    }
    return 0;
}
