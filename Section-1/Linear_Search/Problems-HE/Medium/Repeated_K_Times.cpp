//Used map from the STL to do this
#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n = 0, k = 0;
    cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        m[x]++;
    }
    cin >> k;
    for(auto it : m)
    {
        if(it.second == k)
        {
            cout << it.first;
            break;
        }
    }
}