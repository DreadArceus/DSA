//O(1) with the described math, can also be done in other complexities with searches.
#include <iostream>
using namespace std;
long long solve(int n, long long a, long long b)
{
    long long x = (b*n) / (a+b), y = n - x;
    //the following if is just a case specific implementation of round() found in <cmath>
    if( (b*n) % (a+b) != 0 && y != 0
        && a * x * x + b * y * y > a * (x+1) * (x+1) + b * (y-1) * (y-1) )
    {
        x++;
        y--;
    }
    return a * x * x + b * y * y;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int N = 0, A = 0, B = 0;
        cin >> N >> A >> B;
        long long ans = solve(N, A, B);
        cout << ans << "\n";
    }
}
/*  Math:
    x + y = n => [y = n - x]
    a * x^2 + b * y^2 -> minimise
    a * x^2 + b * (n - x)^2 -> minimise
    => 2ax - 2b(n-x) = 0
    => x = bn / (a+b)
*/