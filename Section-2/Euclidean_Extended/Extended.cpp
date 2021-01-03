//Extended Euclidean makes it possible to find solution of x, y
//  in ax + by = gcd(a, b)
//Seems specific but solution of ax + by = 1 are modulo multiplicative inverses
#include <iostream>
using namespace std;
int gcdExtended(int a, int b, int *x, int *y)
{
    if(a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1 = 0, y1 = 0;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
int main()
{
   int a = 0, b = 0, x = 0, y = 0;
   cin >> a >> b;
   int ans = gcdExtended(a, b, &x, &y);
   cout << a << "*" << x << " + " << b << "*" << y << " = " << ans; 
}