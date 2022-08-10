class DynamicSegTree
{
    struct DSegTreeItem
    {
        int val;
        bool lazy;
        DSegTreeItem *l, *r;
    };

  public:
    DynamicSegTree(int n)
    {
        this->nodes.reserve(32 * 1e5);
        this->make_new();
        this->size = n;
    }
    void rangeUpdate(int x, int y, int v, DSegTreeItem *cur, int l, int r)
    {
        if (cur->lazy)
            propagateLazy(cur, l, r);

        if (y <= l || x >= r)
            return;
        if (l >= x && r <= y)
        {
            cur->lazy = v;
            propagateLazy(cur, l, r);
            return;
        }

        dynamics(cur);
        rangeUpdate(x, y, v, cur->l, l, (r + l) / 2);
        rangeUpdate(x, y, v, cur->r, (r + l) / 2, r);

        cur->val = cur->l->val + cur->r->val;
    }
    int query(int x, int y, DSegTreeItem *cur, int l, int r)
    {
        if (cur->lazy)
            propagateLazy(cur, l, r);

        if (y <= l || x >= r)
            return 0;
        if (l >= x && r <= y)
            return cur->val;

        dynamics(cur);
        return query(x, y, cur->l, l, (r + l) / 2) + query(x, y, cur->r, (r + l) / 2, r);
    }
    void rangeUpdate(int x, int y, int v)
    {
        rangeUpdate(x, y, v, nodes[0], 0, size);
    }
    int query(int x, int y)
    {
        return query(x, y, nodes[0], 0, size);
    }

  private:
    int size;
    vector<DSegTreeItem *> nodes;
    DSegTreeItem *make_new()
    {
        DSegTreeItem *nw = new DSegTreeItem({0, 0, nullptr, nullptr});
        nodes.push_back(nw);
        return nw;
    }
    void dynamics(DSegTreeItem *cur)
    {
        if (cur->l == nullptr)
            cur->l = make_new();

        if (cur->r == nullptr)
            cur->r = make_new();
    }
    void propagateLazy(DSegTreeItem *cur, int l, int r)
    {
        if (l != r - 1)
        {
            dynamics(cur);
            cur->l->lazy = cur->lazy;
            cur->r->lazy = cur->lazy;
        }
        cur->val = (r - l) * cur->lazy, cur->lazy = 0;
    }
};