#include <iostream>
using namespace std;
void printIt(int x)
{
  for(int i = x - 1; i >= 0; i--)
  {
    for(int j = 1; j <= 2*x - 1; j++)
    {
      cout << ((abs(x - j) >= i) ? "*" : " ") << ((j != 2*x - 1) ? " " : "");
    }
    cout << "\n";
  }
  for(int i = 0; i < x; i++)
  {
    for(int j = 1; j <= 2*x - 1; j++)
    {
      cout << ((abs(x - j) >= i) ? "*" : " ") << ((j != 2*x-1) ? " " : "");
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
