//Diophantine means we only consider solutions where all values are integral
//We can find one solution of such an equation with Extended Euclidian
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

void printSolution(int a, int b, int c)
{
    int x = 0, y = 0;
    int gcd = gcdExtended(a, b, &x, &y);
    if(c % gcd != 0)
    {
        cout << "No valid solution";
    }
    else
    {
        x *= c/gcd;
        y *= c/gcd;
        cout << "Solution: " << x << ", " << y;
    }
}
int main()
{
    int a = 0, b = 0, c = 0; //ax + by = c
    cin >> a >> b >> c;
    printSolution(a, b, c);
}