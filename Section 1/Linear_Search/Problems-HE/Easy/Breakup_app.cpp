#include <iostream>
using namespace std;
int compareD(pair<pair<int, int>, pair<int, int>> p)
{
  return ((p.first.first > p.second.first) ? p.first.first : p.second.second);
}
int main()
{
  int n = 0;
  cin >> n;
  pair<pair<int, int>, pair<int, int>> maxD = {{0, 0}, {0, 0}};
  while(n--)
  {

  }
  if(maxD.first.second == maxD.second.second || compareD(maxD) != 19 || compareD(maxD) != 21)
  {
    cout << "No Date";
  }
  else
  {
    cout << "Date";
  }
}
