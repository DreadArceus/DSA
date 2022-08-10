mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

class Treap
{
    typedef struct _Node
    {
        int key, pri, cnt;
        _Node *l, *r;

        _Node(int x) : key(x), pri(rng()), cnt(1), l(nullptr), r(nullptr)
        {
        }
        ~_Node()
        {
            delete l;
            delete r;
        }
        void count()
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
            l->r = merge(l->r, r), l->count();
            return l;
        }

        r->l = merge(l, r->l), r->count();
        return r;
    }

    void split(Node v, int x, Node &l, Node &r)
    {
        l = r = NULL;
        if (!v)
            return;

        if (v->key < x)
            split(v->r, x, v->r, r), l = v;
        else
            split(v->l, x, l, v->l), r = v;
        v->count();
    }

    Node root;

  public:
    Treap() : root(nullptr)
    {
    }
    ~Treap()
    {
        delete root;
    }
    void insert(int x)
    {
        Node l, r;
        split(root, x, l, r);
        root = merge(merge(l, new _Node(x)), r);
    }
    void erase(int x)
    {
        Node l, m, r;

        split(root, x, l, m), split(m, x + 1, m, r);
        assert(m && m->cnt == 1 && m->key == x);
        delete m;

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
            res.push_back(t->key);
            self(self, t->r);
        };
        output(output, root);
        return res;
    }
};