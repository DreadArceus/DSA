//From the one solution, we can shift x and y to find all solutions
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

void printSolutions(int a, int b, int c)
{
    int x = 0, y = 0;
    int gcd = gcdExtended(a, b, &x, &y);
    if(c % gcd != 0)
    {
        cout << "No valid solution";
        return;
    }
    x *= c/gcd;
    y *= c/gcd;
    cout << "Base Solution: " << x << ", " << y << "\n";
    //Shifting:
    for(int i = 0; i < 15; i++)
    {
        x += b/gcd;
        y -= a/gcd;
        cout << "Solution" << i + 1 << ": " << x << ", " << y << "\n";
    }
}
int main()
{
    int a = 0, b = 0, c = 0; //ax + by = c
    cin >> a >> b >> c;
    printSolutions(a, b, c);
}