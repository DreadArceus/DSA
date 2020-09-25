//Print a solid and hollow rectangle using stars, given its length and breadth.
#include <iostream>
using namespace std;
void printRectangles(int l, int b)
{
  int j = b;
  while(j--) //Solid Rectangle
  {
    for(int i = 0; i < l; i++)
    {
      cout << "*" << ((i == l - 1) ? "" : " ");
    }
    cout << "\n";
  }
  cout << "\n";
  j = b;
  while(j--) //Hollow Rectangle
  {
    for(int i = 0; i < l; i++)
    {
      cout << ((i == 0 || i == l - 1 || j == b - 1 || j == 0) ? "*" : " ");
      cout << ((i == l - 1) ? "" : " ");
    }
    cout << "\n";
  }
}
int main()
{
  int l = 0, b = 0;
  cin >> l >> b;
  printRectangles(l, b);
}
