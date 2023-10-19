#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << "NO";
    }
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
        return 0;
    }
}