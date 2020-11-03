//O(nlongn)
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int solve(int a[], int n, int k, int prefixSum[])
{
    int minBuy = ceil((double)n / (k + 1)), sum = 0;
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
    for(int i = 0; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    while(q--)
    {
        int k = 0;
        cin >> k;
        int minCost = solve(a, n, k, prefixSum);
        cout << minCost << "\n";
    }
}