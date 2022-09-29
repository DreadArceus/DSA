template <typename STI, typename MF, typename pLF, typename rLF> class LazySegTree
{
  public:
    LazySegTree(int n, MF &m, pLF &p, rLF &r, STI nl) : merge(m), push(p), resolve(r)
    {
        int sf = 4 * n + 5;
        null = nl;
        nodes.assign(sf, null);
        lazy.assign(sf, {0});
        pending.assign(sf, false);
        size = n;
    }
    void pointUpdate(int x, STI val, int id, int l, int r)
    {
        if (pending[id])
            propagate(id, l, r);
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
    void rangeUpdate(int x, int y, STI val, int id, int l, int r)
    {
        if (pending[id])
            propagate(id, l, r);
        if (y <= l || x >= r)
            return;

        if (l >= x && r <= y)
        {
            pending[id] = true;
            lazy[id] = val;
            propagate(id, l, r);
            return;
        }

        int mid = (l + r) / 2;

        rangeUpdate(x, y, val, 2 * id, l, mid);
        rangeUpdate(x, y, val, 2 * id + 1, mid, r);

        nodes[id] = merge(nodes[2 * id], nodes[2 * id + 1]);
    }
    STI query(int x, int y, int id, int l, int r)
    {
        if (pending[id])
            propagate(id, l, r);
        if (y <= l || x >= r)
            return this->null;

        if (l >= x && r <= y)
            return nodes[id];

        int mid = (l + r) / 2;

        return merge(query(x, y, 2 * id, l, mid), query(x, y, 2 * id + 1, mid, r));
    }
    int descent(int id, int l, int r)
    {
        if (pending[id])
            propagate(id, l, r);

        if (l == r - 1)
            return l ? l : -1;

        int mid = (l + r) / 2;

        if (pending[2 * id + 1])
            propagate(2 * id + 1, mid, r);

        if (nodes[2 * id + 1].e < 0)
            return descent(2 * id + 1, mid, r);
        return descent(2 * id, l, mid);
    }
    void pointUpdate(int x, int val)
    {
        pointUpdate(x, {val}, 1, 0, size);
    }
    void rangeUpdate(int x, int y, int val)
    {
        rangeUpdate(x, y, {val}, 1, 0, size);
    }
    STI query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }
    int descent()
    {
        return descent(1, 0, size);
    }

  private:
    vector<STI> nodes, lazy;
    vector<bool> pending;
    STI null;
    int size;

    MF &merge;
    pLF &push;
    rLF &resolve;

    void propagate(int id, int l, int r)
    {
        if (l != r - 1)
        {
            pending[2 * id] = true, push(lazy[2 * id], lazy[id]);
            pending[2 * id + 1] = true, push(lazy[2 * id + 1], lazy[id]);
        }
        pending[id] = false, resolve(nodes[id], lazy[id]);
    }
};
struct Item
{
    int e;
};
const auto merge = [&](Item &a, Item &b) -> Item {
    Item result;
    result.e = min(a.e, b.e);
    return result;
};
const auto push = [&](Item &a, Item &b) -> void { a.e += b.e; };
const auto resolve = [&](Item &node, Item &lazy) -> void {
    node.e += lazy.e;
    lazy.e = 0;
};
// LazySegTree sa(n, merge, push, resolve, Item({0}));