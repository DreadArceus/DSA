#include <iostream>
using namespace std;
void printIt(int n)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      cout << (( i == 0 || i == n-1
              || j == 0 || j == n - 1
              || i == j || i + j == n - 1) ? "*" : " ");
    }
    cout << "\n";
  }
}
int main()
{
  int n = 0;
  cin >> n;
  if(n % 2 == 0)
  {
    cout << "Invalid Input, exiting...\n";
    exit(0);
  }
  printIt(n);
}
