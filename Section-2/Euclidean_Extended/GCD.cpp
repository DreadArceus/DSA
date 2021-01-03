//Euclidean Algorithm is an efficient way to find GCD, useful for alot
#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    while(a && b)
    {
        if(a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return ((a == 0) ? b : a);
}
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    cout << GCD(a, b);
}