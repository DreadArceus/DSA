#include <iostream>
#include <cmath>
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second
int gcdExtended(int a, int b, int *x, int *y)
{
    *x = 1, *y = 0;
    int x1 = 0, y1 = 1;
    while(b)
    {
        int q = a / b, tempX = *x, tempY = *y;
        *x = x1, *y = y1;
        x1 = tempX - x1 * q;
        y1 = tempY - y1 * q;
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void printSolnInRange(int a, int b, int c, pii l, pii r)
{
    pii base = {0, 0};
    int gcd = gcdExtended(a, b, &base.fi, &base.se);
    if(c % gcd != 0)
    {
        cout << "No valid solutions";
        return;
    }
    base.fi *= c/gcd;
    base.se *= c/gcd;
    int k = ceil(float(gcd * (l.fi - base.fi))/b);
    pii l_sol = {base.fi + k * b/gcd, base.se - k * a/gcd};
    cout << l_sol.fi << " " << l_sol.se;
}

int main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    pii l, r;
    cin >> l.fi >> l.se >> r.fi >> r.se;
    printSolnInRange(a, b, c, l, r);
}