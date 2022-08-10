mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

class CatfishTreap
{
    typedef struct _Node
    {
        int val, pri, cnt;
        _Node *l, *r;

        _Node(int x) : val(x), pri(rng()), cnt(1), l(nullptr), r(nullptr)
        {
        }
        ~_Node()
        {
            delete l;
            delete r;
        }
        void calc()
        {
            cnt = 1;
            if (l)
                cnt += l->cnt;
            if (r)
                cnt += r->cnt;
        }
    } * Node;

    Node merge(Node l, Node r)
    {
        if (!l || !r)
            return l ? l : r;

        if (l->pri < r->pri)
        {
            l->r = merge(l->r, r), l->calc();
            return l;
        }

        r->l = merge(l, r->l), r->calc();
        return r;
    }

    void split(Node v, int x, Node &l, Node &r)
    {
        l = r = NULL;
        if (!v)
            return;

        int cur = v->l ? v->l->cnt : 0;

        if (cur < x)
            split(v->r, x - cur - 1, v->r, r), l = v;
        else
            split(v->l, x, l, v->l), r = v;
        v->calc();
    }

    Node root;

  public:
    CatfishTreap() : root(nullptr)
    {
    }
    ~CatfishTreap()
    {
        delete root;
    }
    void push_back(int x)
    {
        root = merge(root, new _Node(x));
    }
    void insert(int x)
    {
        Node l, r;
        split(root, x, l, r);
        root = merge(merge(l, new _Node(x)), r);
    }
    void erase(int x)
    {
        Node l, tmp, r;
        split(root, x, l, tmp), split(tmp, 1, tmp, r);
        delete tmp;
        root = merge(l, r);
    }
    int size() const
    {
        return root ? root->cnt : 0;
    }
    vector<int> print()
    {
        vector<int> res;
        const auto output = [&](const auto &self, Node t) -> void {
            if (!t)
                return;
            self(self, t->l);
            res.push_back(t->val);
            self(self, t->r);
        };
        output(output, root);
        return res;
    }

    void operate(int a, int b)
    {
    }
};