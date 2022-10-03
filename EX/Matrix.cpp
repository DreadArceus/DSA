class Matrix
{
    int n, m;
    vector<vector<ModInt<mod>>> a;

  public:
    Matrix(int n, int m) : n(n), m(m)
    {
        a.assign(n, vector<ModInt<mod>>(m));
    }
    Matrix(vector<vector<ModInt<mod>>> a) : a(a)
    {
        n = a.size(), m = a[0].size();
    }
    void set(int i, int j, ModInt<mod> val)
    {
        a[i][j] = val;
    }
    void update(int i, int j, ModInt<mod> val)
    {
        a[i][j] += val;
    }
    ModInt<mod> get(int i, int j) const
    {
        return a[i][j];
    }
    Matrix operator*(Matrix other) const
    {
        assert(m == other.n);

        Matrix product = Matrix(n, other.m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < other.m; k++)
                    product.a[i][k] += a[i][j] * other.a[j][k];
        return product;
    }
    Matrix pow(long long p) const
    {
        assert(n == m);
        Matrix res = Matrix(n, m);
        for (int i = 0; i < n; i++)
            res.a[i][i] = 1;

        Matrix tmp(a);

        while (p)
        {
            if (p % 2)
                res = res * tmp;
            p /= 2;
            tmp = tmp * tmp;
        }

        return res;
    }
};