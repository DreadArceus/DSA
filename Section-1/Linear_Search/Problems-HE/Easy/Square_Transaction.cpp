//This problem should actually be done with Binary Search
//Did it with Linear Search anyways.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T = 0;
    cin >> T;
    vector<int> cummSum(T);
    for(int i = 0; i < T; i++)
    {
        cin >> cummSum[i];
        if(i > 0)
        {
            cummSum[i] += cummSum[i-1];
        }
    }
    int q = 0;
    cin >> q;
    while(q--)
    {
        int x = 0;
        cin >> x;
        if(x > cummSum[cummSum.size() - 1])
        {
            cout << -1 << "\n";
            continue;
        }
        for(int i = 0; i < cummSum.size();i++)
        {
            if(x <= cummSum[i])
            {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
}