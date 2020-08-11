#include <iostream>
#include <string>
using namespace std;
void printIt(int n)
{
  //half diamond with deviation pattern:
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j <= i + 1; j++)
    {
      cout << i + 3 << " ";
    }
    cout << "\n";
  }
  for(int i = n - 2; i >= 0; i--)
  {
    for(int j = 1; j <= i + 1; j++)
    {
      cout << i + 3 << " ";
    }
    cout << "\n";
  }
  //stars, deviation - half diamond:
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j <= i + 1; j++)
    {
      cout << i + 1 << ((j == i + 1) ? "" : "*");
    }
    cout << "\n";
  }
  for(int i = n - 1; i >= 0; i--)
  {
    for(int j = 1; j <= i + 1; j++)
    {
      cout << i + 1 << ((j == i + 1) ? "" : "*");
    }
    cout << "\n";
  }
  //AP + custom series + stars half diamond:
  int a = 1;
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j <= i + 1; j++)
    {
      cout << a + j - 1 << ((j == i + 1) ? "" : "*");
    }
    a += i + 1;
    cout << "\n";
  }
  a -= n;
  for(int i = n - 1; i >= 0; i--)
  {
    for(int j = 1; j <= i + 1; j++)
    {
      cout << a + j - 1 << ((j == i + 1) ? "" : "*");
    }
    a -= i;
    cout << "\n";
  }
  //Palindrome + star, half diamond:
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j <= 2 * (i+1) - 1; j++)
    {
      cout << ((j == 1 || j == 2 * (i+1) - 1) ? "*" : to_string(i - abs(i - j + 1))) << ((j == 2 * (i+1) - 1) ? "" : " ");
    }
    cout << "\n";
  }
  for(int i = n - 2; i >= 0; i--)
  {
    for(int j = 1; j <= 2 * (i+1) - 1; j++)
    {
      cout << ((j == 1 || j == 2*(i+1) - 1) ? "*" : to_string(i - abs(i - j + 1))) << ((j == 2 * (i+1) - 1) ? "" : " ");
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
