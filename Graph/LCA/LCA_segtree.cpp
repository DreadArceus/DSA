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
        st = segTree(heights.size());
        for (int i = 0; i < heights.size(); i++)
            st.pointUpdate(i, {heights[i], i});
    }
    int query(int a, int b)
    {
        if (first[a] > first[b])
            swap(a, b);
        return eulerTour[this->st.query(first[a], first[b] + 1).index];
    }

  private:
    struct segTreeItem
    {
        int element;
        int index;
    };
    class segTree
    {
      public:
        segTree()
        {
        }
        segTree(int n)
        {
            this->nodes.resize(4 * n + 5, this->null);
            this->size = n;
        }
        void pointUpdate(int x, segTreeItem val, int index, int l, int r)
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
        segTreeItem query(int x, int y, int index, int l, int r)
        {
            if (y <= l || x >= r)
                return this->null;
            if (l >= x && r <= y)
                return nodes[index];
            return merge(query(x, y, 2 * index, l, (r + l) / 2), query(x, y, 2 * index + 1, (r + l) / 2, r));
        }
        void pointUpdate(int x, segTreeItem val)
        {
            pointUpdate(x, val, 1, 0, size);
        }
        void pointUpdate(int x, int val)
        {
            pointUpdate(x, {val}, 1, 0, size);
        }
        segTreeItem query(int x, int y)
        {
            return query(x, y, 1, 0, size);
        }

      private:
        vector<segTreeItem> nodes;
        segTreeItem null = {INT64_MAX};
        int size;
        segTreeItem merge(segTreeItem a, segTreeItem b)
        {
            if (a.element < b.element)
                return a;
            return b;
        }
    };

    vector<vector<int>> tree;
    vector<int> eulerTour, heights, first;
    segTree st;
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