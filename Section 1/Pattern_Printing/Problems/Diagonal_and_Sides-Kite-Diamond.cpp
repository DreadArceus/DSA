#include <iostream>
using namespace std;
void printIt(int n)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j < 2 * n; j++)
    {
      int dis = abs(n - j);
      if(dis == i || dis == 0 || i == n - 1)
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << "\n";
  }
  for(int i = n - 2; i >= 0; i--)
  {
    for(int j = 1; j < 2 * n; j++)
    {
      int dis = abs(n - j);
      if(dis == i || dis == 0)
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << "\n";
  }
}
int main()
{
  int n = 0;
  cin >> n;
  printIt(n);
}
