#include <iostream>
using namespace std;
void printIt(int n)
{
  //Solid Rhombus:
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 2*n - 1 - i; j++)
    {
      cout << ((j >= n - i) ? "*" : " ");
    }
    cout << "\n";
  }
  cout << "\n";
  //Hollow Rhombus:
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 2*n - 1 - i; j++)
    {
      cout << (( j == n - i
              || j == 2 * n - 2 - i
              || ((i == 0 || i == n - 1) && j > n - i)) ? "*" : " ");
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
