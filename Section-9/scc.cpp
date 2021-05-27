#include <iostream>
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

class SCC
{
public:
    SCC(int n) : n(n)
    {
        graph.resize(n);
        graphT.resize(n);
    };
    void addEdge(int a, int b)
    {
        graph[a].push_back(b);
        graphT[b].push_back(a);
    }
    void arise()
    {
        visited.resize(n);
        exitT.resize(n);
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs1(i);

        reverse(exitT.begin(), exitT.end());

        visited.assign(n, false);
        roots.resize(n);
        for (auto i : exitT)
        {
            if (visited[i])
                continue;
            dfs2(i);
            int root = partial[0];
            rootNodes.push_back(root);
            for (auto v : partial)
                roots[v] = root;
            partial.clear();
        }

        resGraph.resize(n);
        for (int v = 0; v < n; v++)
        {
            for (auto u : graph[v])
            {
                int rootU = roots[u], rootV = roots[v];
                if (rootU != rootV)
                    resGraph[rootV].push_back(rootU);
            }
        }
    }
    vector<int> getRootNodes() { return rootNodes; }
    vector<vector<int>> getCompG() { return resGraph; }

private:
    int n;
    vector<vector<int>> graph, graphT, resGraph;
    vector<int> roots, rootNodes;
    vector<bool> visited;
    vector<int> exitT, partial;
    void dfs1(int source)
    {
        visited[source] = true;
        for (int v : graph[source])
            if (!visited[v])
                dfs1(v);
        exitT.push_back(source);
    }
    void dfs2(int source)
    {
        visited[source] = true;
        partial.push_back(source);
        for (int v : graphT[source])
            if (!visited[v])
                dfs2(v);
    }
};