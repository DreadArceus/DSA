//O(n^2) with just basic prefix sum usage
#include <iostream>
using namespace std;
bool check_for_sub(int a[], int n)
{
    int prefixSum[n];
    prefixSum[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(((i == 0) ? prefixSum[j] : prefixSum[j] - prefixSum[i-1]) == 0)
            {
                return true;
            }
        }
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