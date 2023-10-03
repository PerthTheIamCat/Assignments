#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// NO : 4

int main() 
{
    int i, j, k, l, m, input, count=0;
    char a[5][5] = {
        {'S', 'T', 'L', 'Y', 'R'},
        {'T', 'H', 'E', 'M', 'E'},
        {'A', 'N', 'A', 'G', 'O'},
        {'R', 'O', 'P', 'E', 'S'},
        {'K', 'T', 'T', 'U', 'C'}
    };
    string db[14]={"STLY", "THEME", "THE", "THEM", "HE", "ME", "AN", "GO", "AGO", "ROPE", "OPE", "OGA", "CUT", "OR"};
    string temp;

    cout << "===========================================\n" << endl;
    cout << "                  MENU                     \n" << endl;
    cout << "===========================================\n" << endl;
    cout << "1.Print from front" << endl;
    cout << "2.Print from back" << endl;
    cout << "3.Match data base\n" << endl;
    cout << "Please choose > ";
    cin >> input;
    
    switch (input)
    {
    case 1:
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                for (k = j; k < 5; k++)
                {
                    for (l = j; l <= k; l++)
                    {
                    cout << a[i][l];
                    }
                    cout << " ";
                }
            }
            cout << endl;
        }
        break;
    case 2:
        for (i = 0; i < 5; i++)
        {
            for (j = 4; j >= 0; j--)
            {
                for (k = j; k >= 0; k--)
                {
                    for (l = j; l >= k; l--)
                    {
                    cout << a[i][l];
                    }
                    cout << " ";
                }
            }
            cout << endl;
        }
        break;
    case 3:
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                for (k = j; k < 5; k++)
                {
                    for (l = j; l <= k; l++)
                    {
                    temp += a[i][l];
                    }
                    cout << temp;
                    for (m = 0; m < 14; m++)
                    {
                        if (temp == db[m])
                        {
                            count++;
                            cout << "\tFound " << count;
                            db[m] = "";
                        }
                    }
                    cout << endl;
                    temp = "";
                }
            }
        }
        for (i = 0; i < 5; i++)
        {
            for (j = 4; j >= 0; j--)
            {
                for (k = j; k >= 0; k--)
                {
                    for (l = j; l >= k; l--)
                    {
                    temp += a[i][l];
                    }
                    cout << temp;
                    for (m = 0; m < 14; m++)
                    {
                        if (temp == db[m])
                        {
                            count++;
                            cout << "\tFound " << count;
                            db[m] = "";
                        }
                    }
                    cout << endl;
                    temp = "";
                }
            }
        }
        cout << "Total = " << count;
        break;
    default:
        break;
    }
    return 0;
}