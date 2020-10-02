#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool perfectChecker(int x)
{
    if(x == 1)
    {
        return 0;
    }
    int sum = 1;
    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0)
        {
            sum += i;
            if(i != sqrt(x))
            {
                sum += x/i;
            }
        }
    }
    return sum == x;
}
int perfectFinder(int n)
{
    int cnt = 0, ans = 0;
    for(int i = 1; cnt < n; i++)
    {
        if(perfectChecker(i))
        {
            cnt++;
            ans = i;
        }
    }
    return ans;
}
int main()
{
    int n = 0;
    cin >> n;
    int ans = perfectFinder(n);
    cout << ans;
}