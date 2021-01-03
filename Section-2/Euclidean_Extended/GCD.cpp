//Euclidean Algorithm is an efficient way to find GCD, useful for alot
#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    while(a)
    {
        int temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    cout << GCD(a, b);
}