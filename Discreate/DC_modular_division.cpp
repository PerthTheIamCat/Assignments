#include <iostream>
using namespace std;

struct GCDBox 
{
    long g, s, t;
};

GCDBox find_inverse(GCDBox gcd, long modsys, long divisor)
{
    long t, s;
    if (divisor == 0)
    {
        gcd.g = modsys;
        gcd.s = 1;
        gcd.t = 0;
        return gcd;
    }
    else
    {
        gcd = find_inverse(gcd, divisor, modsys % divisor);
        t = gcd.t;
        s = gcd.s;
        gcd.s = t;
        gcd.t = s - ((modsys/divisor) * t);
        return gcd;
    }
}

int main()
{
    GCDBox gcd;
    long a, b, n, output;
    cin >> a >> b >> n;
    gcd = find_inverse(gcd, n, b);
    if (gcd.t < 0)
    {
        gcd.t += n;
        output = (a * gcd.t) % n;
    }
    else
    {
        output = (a * gcd.t) % n;
    }
    
    cout << output;
    return 0;
}