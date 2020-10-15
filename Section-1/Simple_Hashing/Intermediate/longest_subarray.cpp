//Gotta optimise with hashing, do this later -15-Oct-2020
#include <iostream>
using namespace std;
int solve(int ar[], int n, int k)
{
    for(int size = n; size >= 1; size--)
    {
        for(int i = 0; i <= n - size; i++)
        {
            int sum = 0;
            for(int j = i; j < size + i; j++)
            {
                sum += ar[j];
            }
            if(sum % k == 0)
            {
                return size;
            }
        }
    }
    return 0;
}
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int ar[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int ans = solve(ar, n, k);
    cout << ans;
}