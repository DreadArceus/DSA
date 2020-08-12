//Had to look at the editorial's first paragraph
//The idea is to go through all possible elements of B and check if they are valid.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int> solve(vector<int> A, set<int> C)
{
  set<int> ans;
  for(int x = 1; x < 101; x++) //Check all the possible elements in B
  {
    bool check = true;
    for(int i : A)
    {
      if(C.find(i + x) == C.end()) //If this is ever triggered, the element is not in B
      {
        check = false;
        break;
      }
    }
    if(check)
    {
      ans.insert(x);
    }
  }
  return ans;
}
int main()
{
  int N = 0, M = 0;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  cin >> M;
  set<int> C;
  for(int i = 0; i < M; i++)
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
