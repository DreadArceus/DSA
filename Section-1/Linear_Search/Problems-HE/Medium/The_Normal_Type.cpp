//Tried, ended up with a brute force solution. Too slow.
//Update: more optimised solution by changing the inner checks, faster but still too slow.
//Update: Found out the best method through solution analysis.
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
long long solve(vector<long long> v)
{
    long long dis = set<long long>(v.begin(), v.end()).size();
    long long cnt = 0, locDis = 0, j = 0;
    unordered_map<long long, long long> m;
    m.clear();
    for(long long i = 0; i < v.size(); i++) //Linear Search
    {
        while(j < v.size() && locDis < dis) //find min length subarray from current index i
        {
            m[v[j]]++;
            if(m[v[j]] == 1)
            {
                locDis++;
            }
            j++;
        }
        if(locDis == dis)
        {
            cnt += v.size() - j + 1; //counts all answers from the current subarray
        }
        m[v[i]]--; //leaving the current index
        if(m[v[i]] == 0) //reflect changes in locDis
        {
            locDis--;
        }
    }
    return cnt;
}
int main()
{
    long long n = 0;
    cin >> n;
    vector<long long> v(n);
    for(long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long ans = solve(v);
    cout << ans;
}