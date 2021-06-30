vector<vector<pii>> graph;

vector<int> spfa(int n, int m, int source)
{
    vector<int> d(n, INT64_MAX);
    vector<int> cnt(n, 0);
    vector<int> inqueue(n, false);
    queue<int> q;

    d[source] = 0;
    q.push(source);
    inqueue[source] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inqueue[u] = false;
        for (auto [v, w] : graph[u])
            if (d[u] != INT64_MAX && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (inqueue[v])
                    continue;
                q.push(v);
                inqueue[v] = true;
                cnt[v]++;
                if (cnt[v] > n)
                    return {};
            }
    }
    return d;
}