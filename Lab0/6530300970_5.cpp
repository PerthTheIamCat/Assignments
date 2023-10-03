#include <iostream>
using namespace std;

// Written by Pawit thongkum
// ID : 6530300970
// HW : 5

int main() {

    // Declare variable for matric 3x3
    int matrix[3][3];

    // loop for get input in each rows and columns
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter row #" << i << " : ";
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // loop for show input in each rows and columns
    cout << "Output" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << "(" << i << "," << j << ")" << "  ";
        }
        cout << endl;
    }
    return 0;
}