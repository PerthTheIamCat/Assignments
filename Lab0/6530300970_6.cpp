#include <iostream>
using namespace std;

// Written by Pawit thongkum
// ID : 6530300970
// HW : 6

int main() {

    // Declare variable for matric 3x3
    int matrix[3][3];
    int transposedMatrix[3][3];

    // loop for get input in each rows and columns
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter row #" << i << " : ";
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // loop for transpose the matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
    
    // loop for show input in each rows and columns from transposed matrix
    cout << "Transpose" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << transposedMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}