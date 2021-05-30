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
            top = pq.top();
            pq.pop();
        }
        int v = top.second;
        if (d[v] == INT64_MAX)
            break;

        for (auto [u, w] : graph[v])
            if (d[v] + w < d[u])
                d[u] = d[v] + w, pq.push(make_pair(d[u], u));
    }
    return d;
}