vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u)
{
    visited[u] = true;
    for (int v : graph[u])
        if (!visited[v])
            dfs(v);
}