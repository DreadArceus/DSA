template <typename STI, typename MF> class SegTree
{
  public:
    SegTree(int n, MF &m, STI nl) : null(nl), merge(m)
    {
        int sf = 4 * n + 5;
        nodes.assign(sf, null);
        size = n;
    }
    void pointUpdate(int x, STI val, int id, int l, int r)
    {
        if (x < l || x >= r)
            return;

        if (l == x && r == x + 1)
        {
            nodes[id] = val;
            return;
        }

        int mid = (l + r) / 2;

        pointUpdate(x, val, 2 * id, l, mid);
        pointUpdate(x, val, 2 * id + 1, mid, r);

        nodes[id] = merge(nodes[2 * id], nodes[2 * id + 1]);
    }
    STI query(int x, int y, int id, int l, int r)
    {
        if (y <= l || x >= r)
            return this->null;

        if (l >= x && r <= y)
            return nodes[id];

        int mid = (l + r) / 2;

        return merge(query(x, y, 2 * id, l, mid), query(x, y, 2 * id + 1, mid, r));
    }
    int descent(int k, int id, int l, int r)
    {
        if (l == r - 1)
            return l;

        int mid = (l + r) / 2;

        if (nodes[2 * id].e >= k)
            return descent(k, 2 * id, l, mid);
        return descent(k - nodes[2 * id].e, 2 * id + 1, mid, r);
    }
    void pointUpdate(int x, int val)
    {
        pointUpdate(x, {val}, 1, 0, size);
    }
    STI query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }
    int get(int id)
    {
        return descent(id + 1, 1, 0, size);
    }

  private:
    vector<STI> nodes;
    STI null;
    int size;

    MF &merge;
};

struct Item
{
    int e;
};
const auto merge = [&](Item &a, Item &b) -> Item {
    Item result;
    result.e = a.e + b.e;
    return result;
};
// SegTree st(n, merge, Item({0}));