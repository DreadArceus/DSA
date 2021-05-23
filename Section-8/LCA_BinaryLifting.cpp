#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define pii pair<int, int>

class LCA
{
public:
    LCA(int n) : n(n)
    {
        this->tree.resize(n);
        this->k = 0;
        while ((1 << k) < n)
            k++;
        this->up.resize(n, vector<int>(k + 1));
        this->entryTime.resize(n);
        this->exitTime.resize(n);
    }
    void addEdge(int parent, int child)
    {
        tree[parent].push_back(child);
    }
    void arise()
    {
        this->time = 0;
        dfs(0, 0);
    }
    int query(int a, int b)
    {
        if (ancestorCheck(a, b))
            return a;
        if (ancestorCheck(b, a))
            return b;
        for (int i = k; i >= 0; i--)
            if (!ancestorCheck(up[a][i], b))
                a = up[a][i];
        return up[a][0];
    }

private:
    int n, k;
    vector<vector<int>> tree;
    vector<vector<int>> up;
    int time;
    vector<int> entryTime, exitTime;
    void dfs(int u, int parent)
    {
        entryTime[u] = time++;

        up[u][0] = parent;
        for (int i = 1; i <= k; i++)
            up[u][i] = up[up[u][i - 1]][i - 1];

        for (auto v : tree[u])
            dfs(v, u);

        exitTime[u] = time++;
    }
    bool ancestorCheck(int an, int pr)
    {
        return entryTime[an] <= entryTime[pr] && exitTime[an] >= exitTime[pr];
    }
};