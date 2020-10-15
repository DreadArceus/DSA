//Weird question and solution combo, not doing this
#include <iostream>
#include <unordered_map>
using namespace std;
int maxPoints(int X[], int Y[], int n)
{
    unordered_map<long double, int> hashMap;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            hashMap[double(Y[i] - Y[j]) / (X[i] - X[j])]++;
        }
    }
    int max = 0;
    for(auto it : hashMap)
    {
        if(it.second > max)
        {
            max = it.second;
        }
    }
    return max;
}
int main()
{
    int n = 0;
    cin >> n;
    int x[n], y[n];
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    int ans = maxPoints(x, y, n);
    cout << ans;
}