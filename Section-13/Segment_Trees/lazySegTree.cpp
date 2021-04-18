#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

struct segTreeItem
{
    int element;
};

class lazySegTree
{
public:
    lazySegTree(int n)
    {
        this->nodes.resize(4 * n, this->null);
        this->lazy.resize(4 * n, {0});
        this->size = n;
    }
    void pointUpdate(int x, segTreeItem val, int index, int l, int r)
    {
        manageLazy(index);
        if (l == x && r == x + 1)
        {
            nodes[index] = val;
            return;
        }
        if (x < l || x >= r)
            return;
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
        manageLazy(index);
        if (l >= x && r <= y)
            lazy[index].element += val;
        if (y <= l || x >= r)
            return;
        rangeUpdate(x, y, val, 2 * index, l, (r + l) / 2);
        rangeUpdate(x, y, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    void rangeUpdate(int x, int y, int val)
    {
        rangeUpdate(x, y, val, 1, 0, size);
    }
    segTreeItem query(int x, int y, int index, int l, int r)
    {
        manageLazy(index);
        if (l >= x && r <= y)
            return nodes[index];
        if (y <= l || x >= r)
            return this->null;
        return merge(query(x, y, 2 * index, l, (r + l) / 2),
                     query(x, y, 2 * index + 1, (r + l) / 2, r));
    }
    segTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

private:
    vector<segTreeItem> nodes, lazy;
    segTreeItem null = {INT32_MAX};
    int size;
    void manageLazy(int index)
    {
        if (lazy[index].element != 0)
        {
            if (nodes[2 * index].element == this->null.element)
                nodes[index].element += lazy[index].element;
            else
            {
                lazy[2 * index].element = lazy[index].element;
                lazy[2 * index + 1].element = lazy[index].element;
            }
            lazy[index].element = 0;
        }
    }
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result = {min(a.element, b.element)};
        return result;
    }
};