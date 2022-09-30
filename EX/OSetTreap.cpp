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
    int get(int id)
    {
        const auto descent = [&](const auto &self, Node v, int id) -> int {
            int ck = 1 + (v->l ? v->l->cnt : 0);

            if (id == ck)
                return v->key;

            if (id > ck)
                return self(self, v->r, id - ck);

            return self(self, v->l, id);
        };
        return descent(descent, root, id);
    }
};