class DSU_RB
{
    struct delta
    {
        int u, v;
        int szu;
        int pv;
    };
    vector<int> parent, sz;
    stack<delta> hist;
    int cc;

  public:
    DSU_RB()
    {
    }
    DSU_RB(int n)
    {
        parent.assign(n, -1), sz.assign(n, 0), cc = 0;
    }
    void make_set(int v)
    {
        parent[v] = v, sz[v] = 1, cc++;
    }
    int find_set(int v)
    {
        if (parent[v] == v)
            return v;
        return find_set(parent[v]);
    }
    bool union_sets(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);

        if (u == v)
            return false;

        if (sz[u] < sz[v])
            swap(u, v);
        hist.push({u, v, sz[u], parent[v]});
        sz[u] += sz[v], parent[v] = u, cc--;
        return true;
    }
    void rollback()
    {
        auto [u, v, szu, pv] = hist.top();
        hist.pop();
        sz[u] = szu, parent[v] = pv, cc++;
    }
    int getCC()
    {
        return cc;
    }
};