vector<vector<int>> graph;

bool bipartite(int n)
{
    bool ans = true;
    vector<bool> visited(n, false);
    vector<int> color(n, -1);

    queue<int> q;
    q.push(0);
    visited[0] = true;
    color[0] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : graph[v])
            if (!visited[u])
            {
                q.push(u);
                visited[u] = true;
                color[u] = !color[v];
            }
            else
                ans &= color[u] != color[v];
    }

    return ans;
}