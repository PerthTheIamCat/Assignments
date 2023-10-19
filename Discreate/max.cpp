#include <iostream>
using namespace std;

int main()
{
    int max, a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    cout << max;
    return 0;
}