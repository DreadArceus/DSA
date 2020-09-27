#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool armstrongChecker(long long x)
{
    string s = to_string(x);
    int len = s.length();
    long long sum = 0;
    for(char c : s)
    {
        sum += pow(c - '0', len);
    }
    return sum == x;
}
int armstrongFinder(int n)
{
    int cnt = 0;
    long long ans = 0;
    for(long long i = 0; cnt < n; i++)
    {
        if(armstrongChecker(i))
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
    long long ans = armstrongFinder(n);
    cout << ans;
}