#include <iostream>
using namespace std;
int search(int x, int ar[], int n)
{
  for(int i = 0; i < n; i++) //Linear Search, O(n)
  {
    if(ar[i] == x)
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  int n = 0;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int f = 0;
  cin >> f;
  int ans = search(f, a, n);
  cout << "The result is: " << ans;
}
