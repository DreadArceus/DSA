vector<vector<pii>> graph;

vector<int> dijkstra(int n, int m, int source)
{
    vector<int> d(n, INT64_MAX);
    vector<bool> track(n, false);

    d[source] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!track[j] && (v == -1 || (d[v] > d[j])))
                v = j;

        if (v == -1 || d[v] == INT64_MAX)
            break;

        track[v] = true;
        for (auto [u, w] : graph[v])
            if (d[v] + w < d[u])
                d[u] = d[v] + w;
    }
    return d;
}

vector<int> dijkstraSparse(int n, int m, int source)
{
    vector<int> d(n, INT64_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    d[source] = 0;
    pq.push(make_pair(0, source));
    for (int i = 0; i < n; i++)
    {
        auto top = pq.top();
        pq.pop();
        while (top.first != d[top.second])
        {
            if (pq.empty())
            {
                top = {-1, -1};
                break;
            }
            top = pq.top();
            pq.pop();
        }
        if (top.first == -1)
            break;
        int v = top.second;
        if (d[v] == INT64_MAX)
            break;

        for (auto [u, w] : graph[v])
            if (d[v] + w < d[u])
                d[u] = d[v] + w, pq.push(make_pair(d[u], u));
    }
    return d;
}