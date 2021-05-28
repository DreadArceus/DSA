#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t mod = 1e9 + 7;

struct Edge
{
    int u, v, w;
};
vector<Edge> graph;

vector<int> bellman(int n, int m, int source)
{
    vector<int> d(n, INT64_MAX);
    d[source] = 0;
    bool going = true;
    int cnt = 0;
    while (going)
    {
        if (++cnt == n)
            return {};
        going = false;
        for (int i = 0; i < m; i++)
        {
            int u = graph[i].u, v = graph[i].v, w = graph[i].w;
            if (d[u] != INT64_MAX && d[v] > d[u] + w)
                d[v] = d[u] + w, going = true;
        }
    }
    return d;
}

vector<vector<int>> adj;
vector<int> visited;
void dfs(int source)
{
    visited[source] = true;
    for (auto v : adj[source])
        if (!visited[v])
            dfs(v);
}

int bellmanTargetted(int n, int m, int source, int target)
{
    vector<int> d(n, INT64_MAX);
    d[source] = 0;
    bool going = true, cycle = false;
    int cnt = 0;
    while (going)
    {
        if (++cnt == n)
        {
            cycle = true;
            break;
        }
        going = false;
        for (int i = 0; i < m; i++)
        {
            int u = graph[i].u, v = graph[i].v, w = graph[i].w;
            if (d[u] != INT64_MAX && d[v] > d[u] + w)
                d[v] = d[u] + w, going = true;
        }
    }
    if (cycle)
    {
        queue<int> q;
        for (int i = 0; i < m; i++)
        {
            int u = graph[i].u, v = graph[i].v, w = graph[i].w;
            if (d[u] != INT64_MAX && d[v] > d[u] + w)
                d[v] = d[u] + w, q.push(v);
        }
        visited.resize(n);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (visited[cur])
                continue;
            dfs(cur);
            if (visited[target])
                return INT64_MIN;
        }
    }
    return d[target];
}