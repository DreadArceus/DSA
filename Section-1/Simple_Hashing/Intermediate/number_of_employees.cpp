#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
unordered_map<char, int> solve(unordered_map<char, char> ev)
{
    unordered_map<char, int> ans;
    unordered_map<char, set<char>> hashMap;
    for(auto it : ev)
    {
        if(it.first == it.second)
        {
            continue;
        }
        hashMap[it.second].insert(it.first);
        ans[it.second]++;
    }
    for(auto it : hashMap)
    {
        for(auto it2 : it.second)
        {
            ans[it.first] += ans[it2];
        }
    }
    return ans;
}
int main()
{
    int n = 0;
    cin >> n;
    unordered_map<char, char> employeeTable;
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c >> employeeTable[c];
    }

    unordered_map<char, int> ans = solve(employeeTable);

    for(auto it : ans)
    {
        cout << it.first << ": " << it.second << "\n";
    }
}