class LinkCutTree
{
    typedef struct _Node
    {
        int val, cnt;
        bool rev;
        int self, vir, sum;
        _Node *l, *r, *p, *pp;

        _Node(int y)
            : val(y), cnt(1), rev(false), self(0), vir(0), sum(0), l(nullptr), r(nullptr), p(nullptr), pp(nullptr)
        {
        }
        ~_Node()
        {
            delete l;
            delete r;
        }

        void propagateLazy()
        {
            if (!rev)
                return;

            swap(l, r), rev = false;
            for (auto &c : {l, r})
                if (c)
                    c->rev = !c->rev;
        }
        void calc()
        {
            cnt = 1, sum = self + vir;
            for (auto &c : {l, r})
                if (c)
                    cnt += c->cnt, sum += c->sum;
        }

        void rotateLeft()
        {
            p->r = l;
            if (l)
                l->p = p;
            l = p;
        }
        void rotateRight()
        {
            p->l = r;
            if (r)
                r->p = p;
            r = p;
        }
        bool side()
        {
            return p->l == this;
        }
        void rotate()
        {
            if (side())
                rotateRight();
            else
                rotateLeft();

            swap(pp, p->pp);
            p->calc(), calc();

            Node tmp = p;
            p = p->p, tmp->p = this;
            if (p)
            {
                if (p->r == tmp)
                    p->r = this;
                else
                    p->l = this;
                p->calc();
            }
        }

        void splay()
        {
            while (p)
            {
                if (p->p)
                    p->p->propagateLazy();
                p->propagateLazy(), propagateLazy();

                if (!p->p)
                    rotate();
                else
                {
                    if (p->side() == side())
                        p->rotate(), rotate();
                    else
                        rotate(), rotate();
                }
            }
            propagateLazy();
        }
    } * Node;

    Node access(Node v)
    {
        Node tmp = v;

        v->splay();
        if (v->r)
            v->r->p = nullptr, v->r->pp = v, v->vir += v->r->sum;
        v->r = nullptr, v->calc();

        Node lpar = v;
        while (v->pp)
        {
            Node w = v->pp;

            w->splay();
            if (w->r)
                w->r->p = nullptr, w->r->pp = w, w->vir += w->r->sum;
            w->vir -= v->sum, v->pp = nullptr, w->r = v, v->p = w, w->calc();

            v = w, lpar = w;
        }

        tmp->splay();

        return lpar;
    }
    void makeRoot(Node v)
    {
        access(v), v->rev = !v->rev, access(v);
    }

    vector<Node> sps;
    int treeCount;

  public:
    LinkCutTree(int n)
    {
        treeCount = n;
        sps.assign(n, nullptr);
        for (int i = 0; i < n; i++)
            sps[i] = new _Node(i);
    }
    ~LinkCutTree()
    {
        sps.clear();
    }
    void link(int a, int b)
    {
        Node u = sps[a], v = sps[b];

        makeRoot(u), makeRoot(v);

        assert(!u->l);
        v->pp = u, u->vir += v->sum, u->calc();
        treeCount--;
    }
    void cut(int a, int b)
    {
        Node u = sps[a], v = sps[b];

        makeRoot(u), access(v);

        assert(v->l == u);
        v->l = nullptr, u->p = nullptr, v->calc();
        treeCount++;
    }
    int findRoot(int a)
    {
        Node u = sps[a];

        access(u);
        while (u->l)
            u = u->l;

        return u->val;
    }
    bool connected(int a, int b)
    {
        return findRoot(a) == findRoot(b);
    }
    int getCount()
    {
        return treeCount;
    }

    void updateNode(int a, int x)
    {
        Node u = sps[a];

        access(u), u->self += x, u->calc();
    }
    int subtreeSum(int a, int b)
    {
        Node u = sps[a], v = sps[b];

        makeRoot(v), access(u);

        return u->self + u->vir;
    }
};