//Extended Euclidean makes it possible to find solution of x, y
//  in ax + by = gcd(a, b)
//Seems specific but solution of ax + by = 1 are modulo multiplicative inverses
//Recursive version is much more natural, but here is iterative version:
#include <iostream>
using namespace std;
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
int main()
{
   int a = 0, b = 0, x = 0, y = 0;
   cin >> a >> b;
   int ans = gcdExtended(a, b, &x, &y);
   cout << a << "*" << x << " + " << b << "*" << y << " = " << ans; 
}