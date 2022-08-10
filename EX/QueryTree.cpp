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

struct query
{
    int u, v;
    bool change;
};
class QueryTree
{
    int qn;
    DSU_RB dsu;
    vector<vector<query>> nodes;
    void addQuery(int index, int l, int r, query q, int ql, int qr)
    {
        if (l >= qr || r <= ql)
            return;
        if (l >= ql && r <= qr)
        {
            nodes[index].push_back(q);
            return;
        }

        if (l == r - 1)
            return;

        addQuery(2 * index, l, (l + r) / 2, q, ql, qr);
        addQuery(2 * index + 1, (l + r) / 2, r, q, ql, qr);
    }
    void dfs(int index, int l, int r, vector<int> &ans)
    {
        for (auto &[u, v, change] : nodes[index])
            change = dsu.union_sets(u, v);

        if (l == r - 1)
            ans[l] = dsu.getCC();
        else
            dfs(2 * index, l, (l + r) / 2, ans), dfs(2 * index + 1, (l + r) / 2, r, ans);

        for (auto q : nodes[index])
            if (q.change)
                dsu.rollback();
    }

  public:
    QueryTree(int n, int qn) : qn(qn)
    {
        dsu = DSU_RB(n);
        for (int i = 0; i < n; i++)
            dsu.make_set(i);
        nodes.resize(4 * qn + 5);
    }
    void addQuery(query q, int ql, int qr)
    {
        addQuery(1, 0, qn, q, ql, qr);
    }
    vector<int> arise()
    {
        vector<int> ans(qn);
        dfs(1, 0, qn, ans);
        return ans;
    }
};