//Solved, but the TC needs to be O(N * (logN)^2)
//I think the current TC is O(N^2 * logN)
//Optimising HCF or fusing hexa() and F() into a single function might be the solution.
//Making a list of questions i need to come back to in The Game Plan
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> hexa(int x)
{
  vector<int> revHex(10);
  while(x > 0)
  {
    int i = 0;
    while(pow(16, i) <= x)
    {
      i++;
    }
    i--;
    revHex[i] = x/pow(16, i);
    x %= (int)pow(16, i);
  }
  return revHex;
}
int F(int x)
{
  int ans = 0;
  vector<int> v = hexa(x);
  for(int i : v)
  {
    ans += i;
  }
  return ans;
}
int HCF(int x, int y)
{
  for(int i = min(x, y); i > 1; i--)
  {
    if(x % i == 0 && y % i == 0)
    {
      return i;
    }
  }
  return 1;
}
int solve (int l, int r)
{
  int ans = 0;
  for(int i = l; i <= r; i++)
  {
    ans += HCF(i, F(i)) > 1;
  }
  return ans;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int l = 0, r = 0;
    cin >> l >> r;
    int ans = solve(l, r);
    cout << ans << "\n";
  }
}
