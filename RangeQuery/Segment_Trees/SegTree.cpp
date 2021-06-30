struct SegTreeItem
{
    int element;
};

class SegTree
{
  public:
    SegTree(int n)
    {
        this->nodes.resize(4 * n + 5, this->null);
        this->size = n;
    }
    void pointUpdate(int x, SegTreeItem val, int index, int l, int r)
    {
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
    SegTreeItem query(int x, int y, int index, int l, int r)
    {
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
    SegTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

  private:
    vector<SegTreeItem> nodes;
    SegTreeItem null = {INT64_MAX};
    int size;
    SegTreeItem merge(SegTreeItem a, SegTreeItem b)
    {
        SegTreeItem result;
        result.element = min(a.element, b.element);
        return result;
    }
};