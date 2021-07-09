vector<int> getdivs(int n)
{
    vector<int> divs;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            divs.push_back(i);
            if (i * i != n)
                divs.push_back(n / i);
        }

    return divs;
}