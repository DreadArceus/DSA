const int32_t MAXN = 2e5 + 5;
ModInt<mod> factorial[MAXN];
void prefact()
{
    factorial[0] = 1;
    for (int i = 1; i < MAXN; i++)
        factorial[i] = factorial[i - 1] * i;
}

ModInt<mod> C(int n, int k)
{
    return factorial[n] / (factorial[k] * factorial[n - k]);
}