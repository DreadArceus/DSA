//v1: Brute Force
//v2: Sliding Window
//v3: Teleporting Window
//so far... (26/48) - TLE
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> A, int K)
{
    vector<int> prefixSum(A.size(), 0);
    prefixSum[0] = A[0];
    for(int i = 1; i < A.size(); i++)
    {
        prefixSum[i] = prefixSum[i-1] + A[i];
    }

    for(int len = A.size(); len > 0; len--)
    {
        for(int i = len-1; i < A.size(); i++)
        {
            if(prefixSum[i] - ((i==len-1) ? 0 : prefixSum[i-len]) + K >= len)
            {
                return len;
            }
        }
    }
    return 0;
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = solve(v, k);
    cout << ans;
}