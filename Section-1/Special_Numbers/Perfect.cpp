#include <iostream>
#include <vector>
using namespace std;
bool perfectChecker(int x)
{
    int sum = 1;
    for(int i = 2; i <= x/2; i++)
    {
        if(x % i == 0)
        {
            sum += i;
        }
    }
    return sum == x;
}
int perfectFinder(int n)
{
    int cnt = 0, ans = 0;
    for(int i = 0; cnt < n; i++)
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