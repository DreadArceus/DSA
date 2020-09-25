#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> v, int m)
{
/* Method 1: Linear Search updating the index to return the last one
  int lastOcc = -1;
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] == m)
    {
      lastOcc = i + 1;
    }
  }
  return lastOcc;
*/
/* Method 2: Linear Search from the back, returning the first index.*/
  for(int i = v.size() - 1; i >= 0; i--)
  {
    if(v[i] == m)
    {
      return i + 1;
    }
  }
  return -1;
}
int main()
{
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  int ans = solve(v, m);
  cout << ans;
}
