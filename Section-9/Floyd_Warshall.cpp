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
#define MAX_N 500

// WARNING: UNDIRECTED GRAPH

struct Edge
{
    int u, v, w;
};
vector<Edge> graph;

int store[MAX_N][MAX_N];
void floyd(int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            store[i][j] = INT64_MAX;
    for (int i = 0; i < n; i++)
        store[i][i] = 0;

    for (auto e : graph)
        store[e.u][e.v] = store[e.v][e.u] = min(store[e.v][e.u], e.w);

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (store[i][k] != INT64_MAX && store[k][j] != INT64_MAX)
                    store[i][j] = min(store[i][j], store[i][k] + store[k][j]);
}