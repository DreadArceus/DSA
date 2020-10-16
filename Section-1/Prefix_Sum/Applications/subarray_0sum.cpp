//O(n^2) with just basic prefix sum usage
//O(n) with prefix sum + hashing
#include <iostream>
#include <unordered_map>
using namespace std;
bool check_for_sub(int a[], int n)
{
    int prefixSum[n];
    prefixSum[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    
    unordered_map<int, int> hashMap;
    for(int i = 0; i < n; i++)
    {
        if(prefixSum[i] == 0 || hashMap.find(prefixSum[i]) != hashMap.end()) //if a prefix sum ever repeats, zero sum subarray is found (MATHS)
        {
            return true;
        }
        hashMap[prefixSum[i]] = 1;
    }

    return false;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << ((check_for_sub(a, n)) ? "Yes\n" : "No\n");
    }
}