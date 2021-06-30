class LCA
{
  public:
    LCA(int n)
    {
        this->tree.resize(n);
        this->first.resize(n);
        this->heights.resize(n);
    }
    void addEdge(int parent, int child)
    {
        tree[parent].push_back(child);
    }
    void arise()
    {
        dfs(0, 0);

        int m = eulerTour.size();
        log_2.reserve(m + 1);
        log_2.push_back(-1);
        for (int i = 1; i <= m; i++)
            log_2.push_back(log_2[i / 2] + 1);

        block_size = max(1, log_2[m] / 2);
        block_cnt = (m + block_size - 1) / block_size;

        st.assign(block_cnt, vector<int>(log_2[block_cnt] + 1));
        for (int i = 0, j = 0, b = 0; i < m; i++, j++)
        {
            if (j == block_size)
                j = 0, b++;
            if (j == 0 || min_by_h(i, st[b][0]) == i)
                st[b][0] = i;
        }
        for (int l = 1; l <= log_2[block_cnt]; l++)
        {
            for (int i = 0; i < block_cnt; i++)
            {
                int ni = i + (1 << (l - 1));
                if (ni >= block_cnt)
                    st[i][l] = st[i][l - 1];
                else
                    st[i][l] = min_by_h(st[i][l - 1], st[ni][l - 1]);
            }
        }

        block_mask.assign(block_cnt, 0);
        for (int i = 0, j = 0, b = 0; i < m; i++, j++)
        {
            if (j == block_size)
                j = 0, b++;
            if (j > 0 && (i >= m || min_by_h(i - 1, i) == i - 1))
                block_mask[b] += 1 << (j - 1);
        }

        int possibilities = 1 << (block_size - 1);
        blocks.resize(possibilities);
        for (int b = 0; b < block_cnt; b++)
        {
            int mask = block_mask[b];
            if (!blocks[mask].empty())
                continue;
            blocks[mask].assign(block_size, vector<int>(block_size));
            for (int l = 0; l < block_size; l++)
            {
                blocks[mask][l][l] = l;
                for (int r = l + 1; r < block_size; r++)
                {
                    blocks[mask][l][r] = blocks[mask][l][r - 1];
                    if (b * block_size + r < m)
                        blocks[mask][l][r] =
                            min_by_h(b * block_size + blocks[mask][l][r], b * block_size + r) - b * block_size;
                }
            }
        }
    }
    int query(int a, int b)
    {
        if (first[a] > first[b])
            swap(a, b);
        int ind = this->sparseQuery(first[a], first[b]);
        return eulerTour[ind];
    }

  private:
    vector<vector<int>> tree;
    vector<int> eulerTour, heights, first;
    void dfs(int source, int h)
    {
        eulerTour.push_back(source);
        heights[source] = h;
        first[source] = eulerTour.size() - 1;
        for (auto x : tree[source])
        {
            dfs(x, h + 1);
            eulerTour.push_back(source);
        }
    }
    int min_by_h(int i, int j)
    {
        return heights[eulerTour[i]] < heights[eulerTour[j]] ? i : j;
    }

    int block_size, block_cnt;
    vector<int> log_2;
    vector<vector<int>> st;
    vector<int> block_mask;
    vector<vector<vector<int>>> blocks;
    int lca_in_block(int b, int l, int r)
    {
        return blocks[block_mask[b]][l][r] + b * block_size;
    }
    int sparseQuery(int l, int r)
    {
        int bl = l / block_size;
        int br = r / block_size;
        if (bl == br)
            return lca_in_block(bl, l % block_size, r % block_size);
        int ans1 = lca_in_block(bl, l % block_size, block_size - 1);
        int ans2 = lca_in_block(br, 0, r % block_size);
        int ans = min_by_h(ans1, ans2);
        if (bl + 1 < br)
        {
            int l = log_2[br - bl - 1];
            int ans3 = st[bl + 1][l];
            int ans4 = st[br - (1 << l)][l];
            ans = min_by_h(ans, min_by_h(ans3, ans4));
        }
        return ans;
    }
};