#include <iostream>
#include <algorithm>
using namespace std;

int segTree[10000000];
void build(int index, int l, int r)
{
    if (l == r)
    {
        cin >> segTree[index];
        return;
    }
    build(2 * index + 1, l, (r + l) / 2);
    build(2 * index + 2, (r + l) / 2 + 1, r);
    segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
}
int query(int index, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
        return segTree[index];
    if (l > y || r < x)
        return INT32_MAX;
    return min(query(2 * index + 1, l, (r + l) / 2, x, y),
               query(2 * index + 2, (r + l) / 2 + 1, r, x, y));
}
void pointUpdate(int index, int l, int r, int x, int val)
{
    if (l == x && r == x)
    {
        segTree[index] = val;
        return;
    }
    if (l > x || r < x)
        return;
    pointUpdate(2 * index + 1, l, (r + l) / 2, x, val);
    pointUpdate(2 * index + 2, (r + l) / 2 + 1, r, x, val);
    segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, q = 0;
    cin >> n >> q;
    build(0, 0, n - 1);
    while (q--)
    {
        char c;
        int x = 0, y = 0;
        cin >> c >> x >> y;
        if (c == 'q')
            cout << query(0, 0, n - 1, x - 1, y - 1) << "\n";
        else if (c == 'u')
            pointUpdate(0, 0, n - 1, x - 1, y);
    }
}