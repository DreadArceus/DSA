#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segTreeItem
{
    int element;
};

class segTree
{
public:
    segTree(int n)
    {
        this->nodes.resize(4 * n, this->null);
        this->size = n;
    }
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result = {min(a.element, b.element)};
        return result;
    }
    void pointUpdate(int x, segTreeItem val, int index, int l, int r)
    {
        if (l == x && r == x + 1)
        {
            nodes[index] = val;
            return;
        }
        if (x < l || x >= r)
        {
            return;
        }
        pointUpdate(x, val, 2 * index, l, (r + l) / 2);
        pointUpdate(x, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    void pointUpdate(int x, segTreeItem val)
    {
        pointUpdate(x, val, 1, 0, size);
    }
    void rangeUpdate(int x, int y, int val, int index, int l, int r)
    {
    }
    void rangeUpdate(int x, int y, int val)
    {
        rangeUpdate(x, y, val, 1, 0, size);
    }
    segTreeItem query(int x, int y, int index, int l, int r)
    {
        if (l >= x && r <= y)
        {
            return nodes[index];
        }
        if (y <= l || x >= r)
        {
            return this->null;
        }
        return merge(query(x, y, 2 * index, l, (r + l) / 2),
                     query(x, y, 2 * index + 1, (r + l) / 2, r));
    }
    segTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

private:
    vector<segTreeItem> nodes;
    segTreeItem null = {INT32_MAX};
    int size;
};

int main()
{
    int n = 0, q = 0;
    cin >> n >> q;
    segTree st(n);
    for (int i = 0; i < n; i++)
    {
        int h = 0;
        cin >> h;
        st.pointUpdate(i, {h});
    }
    while (q--)
    {
        char c;
        int x = 0, y = 0;
        cin >> c >> x >> y;
        if (c == 'q')
            cout << st.query(x - 1, y).element << "\n";
        else if (c == 'u')
            st.pointUpdate(x - 1, {y});
    }
}