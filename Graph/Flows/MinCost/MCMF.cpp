class MinCostMaxFlow
{
  public:
    MinCostMaxFlow(int n) : n(n)
    {
        adj.assign(n, vector<int>());
        cost.assign(n, vector<int>(n, 0));
        cap.assign(n, vector<int>(n, 0));
    }
    void addEdge(int from, int to, int cap, int cost)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);

        adj[from].push_back(to);
        adj[to].push_back(from);
        this->cost[from][to] = cost;
        this->cost[to][from] = -cost;
        this->cap[from][to] = cap;
    }
    int arise(int s, int t, int K) // Calculate minimum cost K flow
    {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        assert(s != t);

        int flow = 0;
        int cost = 0;
        vector<int> d, p;
        while (flow < K)
        {
            paths(s, d, p);
            if (d[t] == INF)
                break;

            // find max flow on that path
            int f = K - flow;
            int cur = t;
            while (cur != s)
            {
                f = min(f, cap[p[cur]][cur]);
                cur = p[cur];
            }

            // apply flow
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s)
            {
                cap[p[cur]][cur] -= f;
                cap[cur][p[cur]] += f;
                cur = p[cur];
            }
        }

        if (flow < K)
            return -1;
        else
            return cost;
    }

  private:
    const int INF = 1e9;
    int n;
    vector<vector<int>> adj, cost, cap;

    void paths(int source, vector<int> &d, vector<int> &p)
    {
        vector<bool> inq(n, false);
        d.assign(n, INF);
        p.assign(n, -1);

        queue<int> q;
        q.push(source);
        d[source] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int v : adj[u])
            {
                if (cap[u][v] > 0 && d[v] > d[u] + cost[u][v])
                {
                    d[v] = d[u] + cost[u][v];
                    p[v] = u;
                    if (!inq[v])
                    {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
};