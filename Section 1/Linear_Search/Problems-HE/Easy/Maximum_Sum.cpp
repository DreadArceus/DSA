//Wrong Submissions because, Integer overflow and all negatives
//Otherwise, easy problem.
//Editorial Learning: Dont need to make a vector for the input, 
  //max element can be calculated in the linear search itself.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printAnswer(vector<int> v)
{
  long long sum = 0; //because sum can be very large (integer overflow)
  int count = 0;
  for(int i = 0; i < v.size(); i++) //Linear Search
  {
    if(v[i] >= 0)
    {
      sum += (long long)v[i];
      count++;
    }
  }
  if(sum == 0 && count == 0) //for the all negatives case
  {
    sum = *max_element(v.begin(), v.end());
    count++;
  }
  cout << sum << " " << count;
}
int main()
{
  int n = 0;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  printAnswer(v);
}
