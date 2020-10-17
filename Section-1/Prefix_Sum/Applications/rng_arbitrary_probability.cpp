//This can be done by making a big array with duplicate entries to show the frequency but that is inefficient for big inputs
//The following method uses prefix sum in O(n) time.
#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int arbitrary_randomise(int a[], int f[], int n)
{
    int prefixSum[n];
    prefixSum[0] = f[0];
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i-1] + f[i];
    }

    srand(time(0));
    int normal_rnd = rand() % prefixSum[n-1];

    for(int i = 0; i < n; i++)
    {
        if(normal_rnd <= prefixSum[i] - 1)
        {
            return a[i];
        }
    }
    return -1;
}
int main()
{
    int n = 0;
    cin >> n;
    int a[n], f[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    int rnd = arbitrary_randomise(a, f, n);
    cout << rnd;
}