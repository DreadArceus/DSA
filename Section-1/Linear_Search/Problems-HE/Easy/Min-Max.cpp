//Simple math
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<long long> v(n, 0);
    long long sum = 0, max = 0, min = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] > max)
        {
            max = v[i];
        }
        if(v[i] < min || min == -1)
        {
            min = v[i];
        }
        sum += v[i];
    }
    cout << sum - max << " " << sum - min;
}