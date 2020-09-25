#include <iostream>
using namespace std;
void printIt(int n)
{
  //Right Arrow:
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      cout << (( i == n / 2
              || j == i + n / 2
              || j + i == 3 * n / 2 - 1) ? "*" : " ") << " ";
    }
    cout << "\n";
  }
  //Left Arrow:
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      cout << (( i == n/2
              || j == - i + n / 2
              || - j + i == n / 2) ? "*" : " ") << " ";
    }
    cout << "\n";
  }
  //Right + Left (-><-)
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 2 * n - 1; j++)
    {
      cout << (( i == n/2
              || j == i + n / 2
              || j + i == 3 * n / 2 - 1) ? "*" : " ") << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  //Left + Right (<-->)
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 2 * n - 1; j++)
    {
      cout << (( i == n/2
              || j == i - n / 2
              || j + i == n / 2
              || j == i + 3 * n / 2 - 1
              || j + i == 5 * n / 2 - 2) ? "*" : " ") << " ";
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
