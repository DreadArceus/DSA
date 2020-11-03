//O(nlongn)
//MultiQuery version
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int solve(int n, int k, int prefixSum[])
{
    int minBuy = ceil((double)n / (k + 1));
    return prefixSum[minBuy-1];
}
int main()
{
    int n = 0, q = 0;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    int prefixSum[n];
    prefixSum[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    while(q--)
    {
        int k = 0;
        cin >> k;
        int minCost = solve(n, k, prefixSum);
        cout << minCost << "\n";
    }
}