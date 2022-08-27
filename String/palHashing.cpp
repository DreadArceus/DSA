const int32_t mod = 1e9 + 9;
const auto compute_hash = [&](string const &s) {
    const int p = 31;
    vector<ModInt<mod>> hashval;
    ModInt<mod> p_pow = 1;
    for (char c : s)
    {
        hashval.push_back((!hashval.empty() ? hashval.back() : 0) + p_pow * (c - 'a' + 1));
        p_pow *= p;
    }
    return hashval;
};

string rp(p);
reverse(rp.begin(), rp.end());
vector<ModInt<mod>> s = compute_hash(p);
vector<ModInt<mod>> rs = compute_hash(rp);

int n = p.length();
const auto palCheck = [&](int l, int r) -> bool {
    ModInt<mod> h1 = s[r] - (l ? s[l - 1] : 0);
    int nr = n - r - 1, nl = n - l - 1;
    ModInt<mod> h2 = rs[nl] - (nr ? rs[nr - 1] : 0);
    if (nr - l > 0)
        h2 /= ModInt<mod>(31).pow(nr - l);
    else
        h1 /= ModInt<mod>(31).pow(l - nr);

    return h1 == h2;
};