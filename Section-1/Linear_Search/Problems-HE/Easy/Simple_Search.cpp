//Same exact problem in Demonstration.cpp
#include <iostream>
#include <vector>
using namespace std;
int find(vector<int> v, int x)
{
  for(int i = 0; i < v.size(); i++) //Linear Search
  {
    if(x == v[i])
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  int N = 0, K = 0;
  cin >> N;
  vector<int> v;
  while(N--)
  {
    int loc = 0;
    cin >> loc;
    v.push_back(loc);
  }
  cin >> K;
  cout << find(v, K);
}
