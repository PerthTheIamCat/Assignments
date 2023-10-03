#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// NO : 3

int main()
{
    int i, j, k;
    char a[5][5] = {
        {'S', 'T', 'L', 'Y', 'R'},
        {'T', 'H', 'E', 'M', 'E'},
        {'A', 'N', 'A', 'G', 'O'},
        {'R', 'O', 'P', 'E', 'S'},
        {'K', 'T', 'T', 'U', 'C'}
    };

    cout << "Input: ";
    cin >> i;

    for (j = 0; j < 5; j++)
    {
        for (k = 0; k <= j; k++)
        {
            cout << a[i-1][k];
        }
        cout << " ";
        
    }
    
    return 0;
}