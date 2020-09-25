#include <iostream>
#include <vector>
using namespace std;
void printPP(int n)
{
  //number half pyramid:
  for(int i = 0; i < n; i++)
  {
    int j = 0;
    for(j = 1; j <= (2*i - 1)/2; j++)
    {
      cout << j << " ";
    }
    for(int z = 2*i - 1; z > j - 1; z--)
    {
      cout << z - i + 1 << " ";
    }
    cout << "\n";
  }
  //number full pyramid:
  int a = 1;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j <= 2*n - 1; j++)
    {
      int dis = abs(n - j);
      if(dis == 0)
      {
        cout << a << " ";
      }
      else if(a - dis > 0)
      {
        cout << a - dis <<  " ";
      }
      else
      {
        cout << "  ";
      }
    }
    a++;
    cout << "\n";
  }
  //star-number full pyramid(?)
  for(int i = 0; i < n; i++)
  {
    bool didIt = false;
    for(int j = 0; j <= 2*n; j++)
    {
      int dis = abs(n - j);
      if(dis > i || didIt)
      {
        cout << "*";
        didIt = false;
      }
      else
      {
        cout << i + 1;
        didIt = true;
      }
    }
    cout << "\n";
  }
  //Letters Half Pyramid:
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= 2 * i - 1; j++)
    {
      cout << char('A' - 1 + i - abs(i - j)) << " ";
    }
    cout << "\n";
  }
}
int main()
{
    int n = 0;
    cin >> n;
    printPP(n);
}
