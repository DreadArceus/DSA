#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int>::iterator v_itr;

v_itr binarySearch(v_itr begin, v_itr end, int p)
{
    v_itr mid;
    while(end - begin > 0)
    {
        mid = begin + (end - begin)/2;
        if(*mid > p)
        {
            end = mid;
        }
        else if(*mid <= p)
        {
            begin = mid + 1;
        }
    }
    return begin;
}

int main()
{
    int n = 0, q = 0;
    cin >> n;
    vector<int> v(n), prefixSum(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    prefixSum[0] = v[0];
    for(int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i-1] + v[i];
    cin >> q;
    while(q--)
    {
        int p = 0;
        cin >> p;
        int lastI = binarySearch(v.begin(), v.end(), p) - v.begin();
        cout << lastI << " " << ((lastI == 0) ? 0 : prefixSum[lastI - 1]) << "\n";
    }
}