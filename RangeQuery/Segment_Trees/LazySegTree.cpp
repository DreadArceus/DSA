struct SegTreeItem
{
    int element;
};

class LazySegTree
{
  public:
    LazySegTree(int n)
    {
        this->nodes.resize(4 * n + 5, this->null);
        this->lazy.resize(4 * n + 5, {0});
        this->pendingLazy.resize(4 * n + 5, false);
        this->size = n;
    }
    void pointUpdate(int x, SegTreeItem val, int index, int l, int r)
    {
        if (pendingLazy[index])
            propagateLazy(index, l, r);
        if (x < l || x >= r)
            return;
        if (l == x && r == x + 1)
        {
            nodes[index] = val;
            return;
        }
        pointUpdate(x, val, 2 * index, l, (r + l) / 2);
        pointUpdate(x, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    void rangeUpdate(int x, int y, SegTreeItem val, int index, int l, int r)
    {
        if (pendingLazy[index])
            propagateLazy(index, l, r);
        if (y <= l || x >= r)
            return;
        if (l >= x && r <= y)
        {
            pendingLazy[index] = true;
            lazy[index] = val;
            propagateLazy(index, l, r);
            return;
        }
        rangeUpdate(x, y, val, 2 * index, l, (r + l) / 2);
        rangeUpdate(x, y, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    SegTreeItem query(int x, int y, int index, int l, int r)
    {
        if (pendingLazy[index])
            propagateLazy(index, l, r);
        if (y <= l || x >= r)
            return this->null;
        if (l >= x && r <= y)
            return nodes[index];
        return merge(query(x, y, 2 * index, l, (r + l) / 2), query(x, y, 2 * index + 1, (r + l) / 2, r));
    }
    void pointUpdate(int x, SegTreeItem val)
    {
        pointUpdate(x, val, 1, 0, size);
    }
    void pointUpdate(int x, int val)
    {
        pointUpdate(x, {val}, 1, 0, size);
    }
    void rangeUpdate(int x, int y, SegTreeItem val)
    {
        rangeUpdate(x, y, val, 1, 0, size);
    }
    void rangeUpdate(int x, int y, int val)
    {
        rangeUpdate(x, y, {val}, 1, 0, size);
    }
    SegTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

  private:
    vector<SegTreeItem> nodes, lazy;
    vector<bool> pendingLazy;
    SegTreeItem null = {INT64_MAX};
    int size;
    void propagateLazy(int index, int l, int r)
    {
        if (l != r - 1)
        {
            pendingLazy[2 * index] = true;
            pendingLazy[2 * index + 1] = true;
            lazy[2 * index].element += lazy[index].element;
            lazy[2 * index + 1].element += lazy[index].element;
        }
        nodes[index].element += lazy[index].element;
        lazy[index].element = 0;
        pendingLazy[index] = false;
    }
    SegTreeItem merge(SegTreeItem a, SegTreeItem b)
    {
        SegTreeItem result;
        result.element = min(a.element, b.element);
        return result;
    }
};