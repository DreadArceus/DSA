//Print a half pyramid, using numbers in specific patterns.
#include <iostream>
#include <string>
using namespace std;
void printPyramids(int x)
{
  for(int i = 1; i <= x; i++) //Half Pyramid, numbers in a row-wise AP
  {
    int a = 1;
    for(int j = i; j > 0; j--)
    {
      cout << a++ << ((j != 1) ? " " : "");
    }
    cout << "\n";
  }
  cout << "\n";
  for(int i = x; i > 0; i--) //Inverted Half Pyramid, numbers in a row-wise AP
  {
    int a = 1;
    for(int j = i; j > 0; j--)
    {
      cout << a++ << ((j != 1) ? " " : "");
    }
    cout << "\n";
  }
  cout << "\n";
  int a = 1;
  for(int i = x; i > 0; i--) //Hollow Inverted Half Pyramid, numbers in a Row and Column AP
  {
    int b = a;
    for(int j = i; j > 0; j--)
    {
      cout << ((j == i || j == 1 || i == x) ? to_string(b) : " ") << ((j != 1) ? " " : "");
      b++;
    }
    a++;
    cout << "\n";
  }
  cout << "\n";
  a = 1;
  for(int i = 0; i < x; i++) //Hollow Full Pyramid, numbers in a sidewise AP for 2 sides
  {
    int b = 1;
    for(int j = 1; j <= x + i; j++)
    {
      cout << ((abs(x - j) == i || i == x - 1) ? ((j != x + i) ? to_string(b) : to_string(a)) : " ");
      if(i == x - 1)
      {
        cout << " ";
        j++;
      }
      if(j >= x - i)
      {
        b++;
      }
    }
    a++;
    cout << "\n";
  }
  cout << "\n";
  a = 1;
  for(int i = 0; i < x; i++) //Full Pyramid, columns ans diagonals in AP
  {
    for(int j = 1; j <= x + i; j++)
    {
      cout << ((abs(x - j) <= i) ? to_string(a - abs(j - x)) : " ") << ((j != x+i) ? " " : "");
    }
    a += 2;
    cout << "\n";
  }
  cout << "\n";
  a = 1;
  for(int i = 1; i <= x; i++) //Hollow Half Pyramid, numbers in a 2 sides AP
  {
    for(int j = 0; j < i; j++)
    {
      cout << ((j == 0 || j == i - 1 || i == x) ? to_string(a + j) : " ") << " ";
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
