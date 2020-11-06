//v1: Teleporting Window + Extra preprocessing
//  worked well but i want to see what can reduce the memory used (33.4 mb)
#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> customers, vector<int> grumpy, int X)
{
    vector<int> prefixSum(customers.size());
    prefixSum[0] = customers[0];
    for(int i = 1; i < customers.size(); i++)
    {
        prefixSum[i] = prefixSum[i - 1] + customers[i];
    }
    vector<int> smartPrefix(customers.size());
    smartPrefix[0] = ((grumpy[0] == 0) ? customers[0] : 0);
    for(int i = 1; i < customers.size(); i++)
    {
        smartPrefix[i] = ((grumpy[i] == 0) ? customers[i] : 0) + smartPrefix[i-1];
    }

    int max = 0;
    for(int i = X - 1; i < grumpy.size(); i++)
    {
        int current = prefixSum[i] - ((i != X - 1) ? prefixSum[i - X] : 0);
        current += ((i != X - 1) ? smartPrefix[i - X] : 0) + smartPrefix[customers.size() - 1] - smartPrefix[i];
        if(current > max)
        {
            max = current;
        }
    }
    return max;
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