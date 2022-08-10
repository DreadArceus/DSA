struct SegTreeItem
{
    int element;
};

class SegTree2D
{
  public:
    SegTree2D(int n, int m)
    {
        this->nodes.assign(4 * n + 5, vector<SegTreeItem>(4 * m + 5, null));
        this->szx = n, this->szy = m;
    }
    void update_y(int x, int y, SegTreeItem val, int idx, int lx, int rx, int index, int l, int r)
    {
        if (l == r - 1)
        {
            if (lx == rx - 1)
                nodes[idx][index] = val;
            else
                nodes[idx][index] = merge(nodes[2 * idx][index], nodes[2 * idx + 1][index]);
            return;
        }

        if (y < (r + l) / 2)
            update_y(x, y, val, idx, lx, rx, 2 * index, l, (r + l) / 2);
        else
            update_y(x, y, val, idx, lx, rx, 2 * index + 1, (r + l) / 2, r);
        nodes[idx][index] = merge(nodes[idx][2 * index], nodes[idx][2 * index + 1]);
    }

    void update_x(int x, int y, SegTreeItem val, int index, int l, int r)
    {
        if (l != r - 1)
        {
            if (x < (r + l) / 2)
                update_x(x, y, val, 2 * index, l, (r + l) / 2);
            else
                update_x(x, y, val, 2 * index + 1, (r + l) / 2, r);
        }
        update_y(x, y, val, index, l, r, 1, 0, szy);
    }
    SegTreeItem query_y(int y1, int y2, int index, int l, int r, int x)
    {
        if (y2 <= l || y1 >= r)
            return this->null;
        if (l >= y1 && r <= y2)
            return nodes[x][index];
        return merge(query_y(y1, y2, 2 * index, l, (r + l) / 2, x), query_y(y1, y2, 2 * index + 1, (r + l) / 2, r, x));
    }
    SegTreeItem query_x(int x1, int x2, int y1, int y2, int index, int l, int r)
    {
        if (x2 <= l || x1 >= r)
            return this->null;
        if (l >= x1 && r <= x2)
            return query_y(y1, y2, 1, 0, szy, index);
        return merge(query_x(x1, x2, y1, y2, 2 * index, l, (r + l) / 2),
                     query_x(x1, x2, y1, y2, 2 * index + 1, (r + l) / 2, r));
    }
    void pointUpdate(int x, int y, SegTreeItem val)
    {
        update_x(x, y, val, 1, 0, szx);
    }
    SegTreeItem query(int x1, int x2, int y1, int y2)
    {
        return query_x(x1, x2, y1, y2, 1, 0, szx);
    }

  private:
    vector<vector<SegTreeItem>> nodes;
    SegTreeItem null = {0};
    int szx, szy;
    SegTreeItem merge(SegTreeItem a, SegTreeItem b)
    {
        SegTreeItem result;
        result.element = a.element + b.element;
        return result;
    }
};