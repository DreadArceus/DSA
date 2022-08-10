mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

class PersistentImplicitTreap
{
    typedef struct _Node
    {
        int val, pri, cnt, sum;
        _Node *l, *r;

        _Node(int x) : val(x), pri(rng()), cnt(1), sum(x), l(nullptr), r(nullptr)
        {
        }
        _Node(_Node *cp)
        {
            val = cp->val, pri = cp->pri, cnt = cp->cnt, sum = cp->sum;
            l = cp->l, r = cp->r;
        }
        ~_Node()
        {
            delete l;
            delete r;
        }
        void calc()
        {
            cnt = 1, sum = val;
            if (l)
                cnt += l->cnt, sum += l->sum;
            if (r)
                cnt += r->cnt, sum += r->sum;
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

    vector<Node> root;

  public:
    PersistentImplicitTreap()
    {
        root.assign(1, nullptr);
    }
    ~PersistentImplicitTreap()
    {
        root.clear();
    }
    void push_back(int x)
    {
        root[0] = merge(root[0], new _Node(x));
    }

    void update(int k, int a, int x)
    {
        const auto persist = [&](const auto &self, Node v, int id) -> Node {
            if (!v)
                return nullptr;

            int cur = v->l ? v->l->cnt : 0;
            Node nw = new _Node(v);

            if (cur > id)
                nw->l = self(self, nw->l, id);
            else if (cur == id)
                nw->val = x;
            else
                nw->r = self(self, nw->r, id - cur - 1);

            nw->calc();
            return nw;
        };
        root[k] = persist(persist, root[k], a);
    }
    int sum(int k, int a, int b)
    {
        Node l, tmp, r;
        split(root[k], a, l, tmp), split(tmp, b - a + 1, tmp, r);
        int res = tmp->sum;
        root[k] = merge(merge(l, tmp), r);
        return res;
    }
    void copy(int k)
    {
        Node rt = new _Node(root[k]);
        root.push_back(rt);
    }
};