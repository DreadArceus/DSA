#include <iostream>
#include <queue>
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
queue<pair<int, pii>> q;

bool bfs(int source, int str)
{
    q = queue<pair<int, pii>>();
    q.push(make_pair(source, make_pair(-1, str)));
    while (!q.empty())
    {
        int s = q.front().first, parent = q.front().second.first;
        str = q.front().second.second;
        if (visited[s])
            return false;
        visited[s] = true;
        q.pop();
        if (str == 0)
            continue;
        for (auto node : graph[s])
        {
            if (visited[node] && node != parent)
                return false;
            q.push(make_pair(node, make_pair(s, str - 1)));
        }
    }
    return true;
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
        valid = bfs(k, s);
    }
    for (auto guarded : visited)
    {
        if (!guarded)
        {
            valid = false;
            break;
        }
    }
    cout << (valid ? "Yes" : "No") << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}
