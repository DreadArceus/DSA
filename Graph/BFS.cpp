#define pii pair<int, int>

vector<vector<int>> graph;

vector<int> bfs(int n, int source)
{
    vector<bool> visited(n, false);
    vector<int> dist(n, INT32_MAX);

    queue<int> q;
    q.push(source);
    visited[source] = true;
    dist[source] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : graph[v])
            if (!visited[u])
            {
                q.push(u);
                visited[u] = true;
                dist[u] = dist[v] + 1;
            }
    }

    return dist;
}