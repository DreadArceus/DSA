#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long

struct SpTItem
{
    int element;
};

class SparseTable
{
public:
    SparseTable(int n) : n(n)
    {
        this->activated = false;
        this->k = 0;
        while ((1 << k) < n)
            k++;
        this->table.resize(n, vector<SpTItem>(k + 1));
        this->log.resize(n + 1);
    }
    void insert(int ind, SpTItem val)
    {
        this->table[ind][0] = val;
        this->activated = false;
    }
    SpTItem query(int l, int r)
    {
        if (!this->activated)
            this->arise();
        int j = log[r - l + 1];
        return merge(table[l][j], table[r - (1 << j) + 1][j]);
    }

private:
    int n, k;
    bool activated;
    vector<vector<SpTItem>> table;
    vector<int> log;
    SpTItem null = {INT32_MAX};
    void arise()
    {
        for (int j = 1; j <= k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        log[1] = 0;
        for (int i = 2; i <= n; i++)
            log[i] = log[i / 2] + 1;
        activated = true;
    }
    SpTItem merge(SpTItem x, SpTItem y)
    {
        SpTItem res;
        res.element = min(x.element, y.element);
        return res;
    }
};