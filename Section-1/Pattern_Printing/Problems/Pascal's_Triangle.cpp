#include <iostream>
#include <vector>
using namespace std;
void printPT(int n)
{
  vector<vector<int> > v(n);
  v[0] = {1};
  for(int i = 1; i < n; i++)
  {
    v[i].resize(v[i-1].size() + 1);
    v[i][0] = 1;
    v[i][v[i].size() - 1] = 1;
    for(int j = 1; j < v[i].size() - 1; j++)
    {
      v[i][j] = v[i-1][j-1] + v[i-1][j];
    }
  }
  for(vector<int> x : v)
  {
    for(int a : x)
    {
      cout << a << " ";
    }
    cout << "\n";
  }
}
int main()
{
  int n = 0;
  cin >> n;
  printPT(n);
}
