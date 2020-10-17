//O(nlongn) but can be further optimised by a very specific algorithm into O(nlogm) where m = minBuy
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int solve(int a[], int n, int k)
{
    int minBuy = ceil((double)n / (k + 1)), sum = 0;
    sort(a, a+n);
    for(int i = 0; i < minBuy; i++)
    {
        sum += a[i];
    }
    return sum;
}
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int minCost = solve(a, n ,k);
    cout << minCost;
}