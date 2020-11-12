//string, vector, pair, set
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool defSort(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s = 0, b = 0;
    cin >> s >> b;
    int ships[s];
    vector<pair<int, int>> bases(b);
    for(int i = 0; i < s; i++)
    {
        cin >> ships[i];
    }
    for(int i = 0; i < b; i++)
    {
        cin >> bases[i].first >> bases[i].second;
    }

    sort(bases.begin(), bases.end(), defSort);
    long goldSum[b];
    goldSum[0] = bases[0].second;
    for(int i = 1; i < b; i++)
    {
        goldSum[i] = goldSum[i - 1] + bases[i].second;
    }

    for(int shipPower : ships)
    {
        int index = upper_bound(bases.begin(), bases.end(), pair<int, int>{shipPower, INT32_MAX}) - bases.begin() - 1;
        cout << ((index >= 0) ? goldSum[index] : 0) << " ";
    }
}