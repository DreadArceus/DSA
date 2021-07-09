bool prime[15000105];
void sieve(int n)
{
    for (int i = 0; i <= n; i++)
        prime[i] = 1;
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
    prime[1] = prime[0] = 0;
}

vector<int> primelist;

void genprimes(int n)
{
    sieve(n + 1);
    for (int i = 2; i <= n; i++)
        if (prime[i])
            primelist.push_back(i);
}

vector<int> factors(int n)
{
    assert(primelist.size() != 0);
    vector<int> facs;

    for (int i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++)
        while (n % primelist[i] == 0)
            n /= primelist[i], facs.push_back(primelist[i]);
    if (n > 1)
        facs.push_back(n);
    sort(facs.begin(), facs.end());
    return facs;
}