int binpow(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int inverse(int x)
{
    return binpow(x, mod - 2, mod);
}

int factorial[MAXN];
void prefact()
{
    factorial[0] = 1;
    for (int i = 1; i < MAXN; i++)
        factorial[i] = factorial[i - 1] * i % mod;
}

int C(int n, int k)
{
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % mod) % mod;
}