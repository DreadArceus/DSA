template <class T> class FenTree
{

  public:
    FenTree() : _n(0)
    {
    }
    explicit FenTree(int n) : _n(n), data(n)
    {
    }

    void add(int p, T x)
    {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n)
        {
            data[p - 1] += uint64_t(x);
            p += p & -p;
        }
    }

    T sum(int l, int r)
    {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    vector<uint64_t> data;

    uint64_t sum(int r)
    {
        uint64_t s = 0;
        while (r > 0)
        {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};