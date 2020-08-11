#include <iostream>
#include <set>
using namespace std;
set<int> solve(set<int> x, set<int> y)
{
  set<int> ans;
  for(auto it : x)
  {
    auto it2 = y.begin();
    for(it2++; it2 != y.begin() + y.size() - 2; it2++)
    {
      ans.insert(*it2 - it);
    }
  }
  return ans;
}
int main()
{
  int N = 0, M = 0;
  set<int> A, C;
  cin >> N;
  while(N--)
  {
    int loc = 0;
    cin >> loc;
    A.insert(loc);
  }
  cin >> M;
  while(M--)
  {
    int loc = 0;
    cin >> loc;
    C.insert(loc);
  }
  set<int> B = solve(A, C);
  for(auto it : B)
  {
    cout << it << " ";
  }
}
