//Easy to do in O(n^2) time complexity but O(n) is optimal, therefore:
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int ar[n];
    unordered_map<int, pair<bool, int>> hashMap;
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
        if(!hashMap[ar[i]].first)
        {
            hashMap[ar[i]].second = -1 * i;
            hashMap[ar[i]].first = true;
        }
    }
    int maxDis = 0;
    for(int i = 0; i < n; i++)
    {
        hashMap[ar[i]].first = false;
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if(!hashMap[ar[i]].first)
        {
            hashMap[ar[i]].second += i;
            if(hashMap[ar[i]].second > maxDis)
            {
                maxDis = hashMap[ar[i]].second;
            }
            hashMap[ar[i]].first = true;
        }
    }
    cout << maxDis;
}