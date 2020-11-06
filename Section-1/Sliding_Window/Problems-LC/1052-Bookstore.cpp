//v1: Teleporting Window + Extra preprocessing
//v2: Sliding Window
//  normal SW works just fine, the added layer of data makes this solution harder to get to
#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> customers, vector<int> grumpy, int X)
{
    int sum = 0, maxExtra = 0, extra = 0;
    for(int i = 0; i < grumpy.size(); i++)
    {
        if(grumpy[i] == 0)
        {
            sum += customers[i];
        }
        else
        {
            extra += customers[i];
        }

        if(i >= X && grumpy[i-X] == 1)
        {
            extra -= customers[i-X];
        }

        if(extra > maxExtra)
        {
            maxExtra = extra;
        }
    }
    return sum + maxExtra;
}
int main()
{
    int n = 0, x = 0;
    cin >> n >> x;
    vector<int> customers(n), grumpy(n);
    for(int i = 0; i < n; i++)
    {
        cin >> customers[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> grumpy[i];
    }
    int ans = solve(customers, grumpy, x);
    cout << ans;
}