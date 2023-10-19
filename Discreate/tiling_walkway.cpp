#include <iostream>
using namespace std;

int count_time(int n)
{
    int a[n];
    a[0] = 0;
    a[1] = 2;
    a[2] = 5;
    if (n == 1)
    {
        return a[1];
    }
    else if (n == 2)
    {
        return a[2];    
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            a[i] = a[i-2] + a[i-1]; 
        }
    }
    return a[n];
}

int main()
{
    int n;
    cin >> n;
    cout << n;
    return 0;
}