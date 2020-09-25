#include <iostream>
using namespace std;
void printDiamonds(int n)
{
  //full diamond:
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j < 2 * n; j++)
    {
      int dis = abs(n - j);
      if(dis <= i)
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
  for(int i = n - 1; i >= 0; i--)
  {
    for(int j = 1; j < 2 * n; j++)
    {
      int dis = abs(n - j);
      if(dis <= i)
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
  //hollow full diamond:
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j < 2 * n; j++)
    {
      int dis = abs(n - j);
      if(dis == i)
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
  for(int i = n - 1; i >= 0; i--)
  {
    for(int j = 1; j < 2 * n; j++)
    {
      int dis = abs(n - j);
      if(dis == i)
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
  //half diamond:
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j <= i + 1; j++)
    {
      cout << "*" << " ";
    }
    cout << "\n";
  }
  for(int i = n - 2; i >= 0; i--)
  {
    for(int j = 1; j <= i + 1; j++)
    {
      cout << "*" << " ";
    }
    cout << "\n";
  }
}
int main()
{
  int n = 0;
  cin >> n;
  printDiamonds(n);
}
