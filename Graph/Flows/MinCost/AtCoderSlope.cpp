template <class Cap, class Cost> class MCF
{
  public:
    MCF(int n) : _n(n), g(n)
    {
    }

    int addEdge(int from, int to, Cap cap, Cost cost)
    {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to)
            to_id++;
        g[from].push_back(_edge{to, to_id, cap, cost});
        g[to].push_back(_edge{from, from_id, 0, -cost});
        return m;
    }

    struct edge
    {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i)
    {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    vector<edge> edges()
    {
        int m = int(pos.size());
        vector<edge> result(m);
        for (int i = 0; i < m; i++)
            result[i] = get_edge(i);
        return result;
    }

    pair<Cap, Cost> flow(int s, int t)
    {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    pair<Cap, Cost> flow(int s, int t, Cap flow_limit)
    {
        return slope(s, t, flow_limit).back();
    }
    vector<pair<Cap, Cost>> slope(int s, int t)
    {
        return slope(s, t, numeric_limits<Cap>::max());
    }
    vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit)
    {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
        // variants (C = maxcost):
        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
        // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge
        vector<Cost> dual(_n, 0), dist(_n);
        vector<int> pv(_n), pe(_n);
        vector<bool> vis(_n);
        auto dual_ref = [&]() {
            fill(dist.begin(), dist.end(), numeric_limits<Cost>::max());
            fill(pv.begin(), pv.end(), -1);
            fill(pe.begin(), pe.end(), -1);
            fill(vis.begin(), vis.end(), false);
            struct Q
            {
                Cost key;
                int to;
                bool operator<(Q r) const
                {
                    return key > r.key;
                }
            };
            priority_queue<Q> que;
            dist[s] = 0;
            que.push(Q{0, s});
            while (!que.empty())
            {
                int v = que.top().to;
                que.pop();
                if (vis[v])
                    continue;
                vis[v] = true;
                if (v == t)
                    break;
                // dist[v] = shortest(s, v) + dual[s] - dual[v]
                // dist[v] >= 0 (all reduced cost are positive)
                // dist[v] <= (n-1)C
                for (int i = 0; i < int(g[v].size()); i++)
                {
                    auto e = g[v][i];
                    if (vis[e.to] || !e.cap)
                        continue;
                    // |-dual[e.to] + dual[v]| <= (n-1)C
                    // cost <= C - -(n-1)C + 0 = nC
                    Cost cost = e.cost - dual[e.to] + dual[v];
                    if (dist[e.to] - dist[v] > cost)
                    {
                        dist[e.to] = dist[v] + cost;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        que.push(Q{dist[e.to], e.to});
                    }
                }
            }
            if (!vis[t])
                return false;

            for (int v = 0; v < _n; v++)
            {
                if (!vis[v])
                    continue;
                // dual[v] = dual[v] - dist[t] + dist[v]
                //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s] - dual[v])
                //         = - shortest(s, t) + dual[t] + shortest(s, v)
                //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C
                dual[v] -= dist[t] - dist[v];
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        vector<pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit)
        {
            if (!dual_ref())
                break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v])
                c = min(c, g[pv[v]][pe[v]].cap);
            for (int v = t; v != s; v = pv[v])
            {
                auto &e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d)
                result.pop_back();
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }

  private:
    int _n;

    struct _edge
    {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
};