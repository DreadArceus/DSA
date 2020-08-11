#include <iostream>
using namespace std;
void printFT(int n)
{
  int a = 1;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j <= i; j++)
    {
      cout << a++ << " ";
    }
    cout << "\n";
  }
}
int main()
{
  int n = 0;
  cin >> n;
  printFT(n);
}
