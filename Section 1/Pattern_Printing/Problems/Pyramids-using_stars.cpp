//Print a half/full pyramid/inverted pyramid, hollow half/full pyramid/inverted pyramid, using stars.
#include <iostream>
using namespace std;
void printPyramids(int x)
{
  for(int i = 1; i <= x; i++) //Half Pyramid
  {
    for(int j = i; j > 0; j--)
    {
      cout << "*" << ((j != 1) ? " " : "");
    }
    cout << "\n";
  }
  cout << "\n";
  for(int i = x; i > 0; i--) //Inverted Half Pyramid
  {
    for(int j = i; j > 0; j--)
    {
      cout << "*" << ((j != 1) ? " " : "");
    }
    cout << "\n";
  }
  cout << "\n";
  for(int i = 0; i < x; i++) //Full Pyramid
  {
    for(int j = 1; j <= x + i; j++)
    {
      cout << ((abs(x - j) <= i) ? "*" : " ") << ((j != x+i) ? " " : "");
    }
    cout << "\n";
  }
  cout << "\n";
  for(int i = x - 1; i >= 0; i--) //Inverted Full Pyramid
  {
    for(int j = 1; j <= x + i; j++)
    {
      cout << ((abs(x - j) <= i) ? "*" : " ") << ((j != x+i) ? " " : "");
    }
    cout << "\n";
  }
  cout << "\n";
  for(int i = 1; i <= x; i++) //Hollow Half Pyramid
  {
    for(int j = i; j > 0; j--)
    {
      cout << ((j == i || j == 1 || i == x) ? "*" : " ") << ((j != 1) ? " " : "");
    }
    cout << "\n";
  }
  cout << "\n";
  for(int i = x; i > 0; i--) //Hollow Inverted Half Pyramid
  {
    for(int j = i; j > 0; j--)
    {
      cout << ((j == i || j == 1 || i == x) ? "*" : " ") << ((j != 1) ? " " : "");
    }
    cout << "\n";
  }
  cout << "\n";
  for(int i = 0; i < x; i++) //Hollow Full Pyramid
  {
    for(int j = 1; j <= x + i; j++)
    {
      cout << ((abs(x - j) == i || i == x - 1) ? "*" : " ") << ((j != x+i) ? " " : "");
    }
    cout << "\n";
  }
  cout << "\n";
  for(int i = x - 1; i >= 0; i--) //Hollow Inverted Full Pyramid
  {
    for(int j = 1; j <= x + i; j++)
    {
      cout << ((abs(x - j) == i || i == x - 1) ? "*" : " ") << ((j != x+i) ? " " : "");
    }
    cout << "\n";
  }
}
int main()
{
  int h = 0;
  cin >> h;
  printPyramids(h);
}
