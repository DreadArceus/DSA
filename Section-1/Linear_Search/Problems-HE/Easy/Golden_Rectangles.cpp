//Editorial says converting the cross multiplication before the comparison is "safer".
//other than that, simple problem.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<pair<int, int>> v)
{
    int cnt = 0;
    for(pair<int, int> p : v)
    {
        double ratio = double(p.first)/double(p.second);
        if(ratio >= 1.6 && ratio <= 1.7)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int n = 0;
    cin >> n;
    vector<pair<int, int>> rectangles(n);
    for(int i = 0; i < n; i++)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        rectangles[i] = {max(x, y), min(x, y)};
    }
    int count = solve(rectangles);
    cout << count;
}