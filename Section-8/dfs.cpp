#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

vector<vector<int>> graph;
vector<bool> visited;

bool dfs(int source, int maxDepth, int prev)
{
    int good = true;
    if(visited[source]) return false;
    visited[source] = true;
    if(maxDepth == 0) return true;
    for (auto node : graph[source])
    {
        if(!good) break;
        if(node == prev) continue;
        good = dfs(node, maxDepth - 1, source);
    }
    return good;
}

void solveCase()
{
    int n = 0, r = 0, m = 0;
    cin >> n >> r >> m;
    graph.clear();
    visited.clear();
    graph.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < r; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int valid = true;
    while (m--)
    {
        int k = 0, s = 0;
        cin >> k >> s;
        k--;
        if (!valid)
            continue;
        valid = dfs(k, s, -1);
    }
    for(auto guarded : visited)
    {
        if(!guarded)
        {
            valid = false;
            break;
        }
    }
    cout << (valid ? "Yes" : "No") << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}