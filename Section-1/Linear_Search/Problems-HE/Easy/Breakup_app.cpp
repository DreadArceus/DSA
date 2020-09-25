//Really cool style of input
//Learned exception handling here
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  string s = "", pers = "";
  vector<int> dateGrid(30, 0);
  while(n--)
  {
    cin >> pers; 
    getline(cin, s);
    int x = 1;
    if(pers == "G:")
    {
      x = 2;
    }
    string cur = "";
    for(char c : s)
    {
      if(c == ' ')
      {
        try
        {
          stoi(cur);
        }
        catch(invalid_argument)
        {
          cur = "";
          continue;
        }
        dateGrid[stoi(cur) - 1] += x;
        cur = "";
      }
      else
      {
        cur += c;
      }
    }
    try
    {
      stoi(cur);
    }
    catch(invalid_argument)
    {
      continue;
    }
    dateGrid[stoi(cur) - 1] += x;
  }
  int max = 0, date = 0;
  for(int i = 0; i < 30; i++)
  {
    if(dateGrid[i] > max)
    {
      max = dateGrid[i];
      date = i;
    }
  }
  for(int i = 0; i < 30; i++)
  {
    if(dateGrid[i] == max && i != date)
    {
      date = 0;
      break;
    }
  }
  cout << ((date == 18 || date == 19) ? "Date" : "No Date");
}
