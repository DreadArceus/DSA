//can also be done with DP apparently
#include <iostream>
using namespace std;
int get_eq_index(int a[], int n)
{
    int prefixSum[n];
    prefixSum[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i-1] + a[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(prefixSum[i-1] == prefixSum[n-1] - prefixSum[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int eq = get_eq_index(a, n);
    cout << eq;
}