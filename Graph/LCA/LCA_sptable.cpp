class LCA
{
  public:
    LCA(int n)
    {
        this->tree.resize(n);
        this->first.resize(n);
    }
    void addEdge(int parent, int child)
    {
        tree[parent].push_back(child);
    }
    void arise()
    {
        dfs(0, 0);
        st = SparseTable(heights.size());
        for (int i = 0; i < heights.size(); i++)
            st.insert(i, {heights[i], i});
    }
    int query(int a, int b)
    {
        if (first[a] > first[b])
            swap(a, b);
        return eulerTour[this->st.query(first[a], first[b]).index];
    }

  private:
    struct SpTItem
    {
        int element;
        int index;
    };
    class SparseTable
    {
      public:
        SparseTable()
        {
        }
        SparseTable(int n) : n(n)
        {
            this->activated = false;
            this->k = 0;
            while ((1 << k) < n)
                k++;
            this->table.resize(n, vector<SpTItem>(k + 1));
            this->log.resize(n + 1);
        }
        void insert(int ind, SpTItem val)
        {
            this->table[ind][0] = val;
            this->activated = false;
        }
        SpTItem query(int l, int r)
        {
            if (!this->activated)
                this->arise();
            int j = log[r - l + 1];
            return merge(table[l][j], table[r - (1 << j) + 1][j]);
        }

      private:
        int n, k;
        bool activated;
        vector<vector<SpTItem>> table;
        vector<int> log;
        SpTItem null = {INT32_MAX};
        void arise()
        {
            for (int j = 1; j <= k; j++)
                for (int i = 0; i + (1 << j) <= n; i++)
                    table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            log[1] = 0;
            for (int i = 2; i <= n; i++)
                log[i] = log[i / 2] + 1;
            activated = true;
        }
        SpTItem merge(SpTItem x, SpTItem y)
        {
            if (x.element < y.element)
                return x;
            return y;
        }
    };

    vector<vector<int>> tree;
    vector<int> eulerTour, heights, first;
    SparseTable st;
    void dfs(int source, int h)
    {
        eulerTour.push_back(source);
        heights.push_back(h);
        first[source] = eulerTour.size() - 1;
        for (auto x : tree[source])
        {
            dfs(x, h + 1);
            eulerTour.push_back(source);
            heights.push_back(h);
        }
    }
};