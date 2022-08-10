class SplayTree
{
    typedef struct _Node
    {
        int key, val, cnt, sum;
        _Node *l, *r, *p;

        _Node(int x, int y) : key(x), val(y), cnt(1), sum(y), l(nullptr), r(nullptr), p(nullptr)
        {
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

        void orphanage()
        {
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
        void rotateLeft()
        {
            p->r = l;
            if (l)
                l->p = p;
            l = p;

            orphanage();
        }
        void rotateRight()
        {
            p->l = r;
            if (r)
                r->p = p;
            r = p;

            orphanage();
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
        }
    } * Node;

    void splay(Node v)
    {
        while (v->p)
        {
            if (!v->p->p)
                v->rotate();
            else
            {
                if (v->p->side() == v->side())
                    v->p->rotate(), v->rotate();
                else
                    v->rotate(), v->rotate();
            }
        }
    }

    Node merge(Node l, Node r)
    {
        if (!l || !r)
            return l ? l : r;

        while (l->r)
            l = l->r;
        splay(l);

        l->r = r, l->calc();
        r->p = l;

        return l;
    }

    void split(Node v, int key, Node &l, Node &r)
    {
        l = r = NULL;
        if (!v)
            return;

        while (v->key != key)
        {
            if (v->key > key)
            {
                if (v->l)
                    v = v->l;
                else
                {
                    r = v;
                    splay(v);
                    return;
                }
            }
            else
            {
                if (v->r)
                    v = v->r;
                else
                {
                    l = v;
                    splay(v);
                    return;
                }
            }
        }
        splay(v);

        l = v->l;
        if (l)
            l->p = nullptr;
        r = v;
        if (r)
            r->l = nullptr, r->calc();
    }

    Node root;

  public:
    SplayTree() : root(nullptr)
    {
    }
    ~SplayTree()
    {
        delete root;
    }

    int get_sz()
    {
        return root ? root->cnt : 0;
    }
    void push_back(int u)
    {
        root = merge(root, new _Node(this->get_sz(), u));
    }

    void update(int k, int u)
    {
        Node v = root;
        while (v && v->key != k)
        {
            if (v->key > k)
                v = v->l;
            else
                v = v->r;
        }
        assert(v != nullptr);
        splay(v), root = v;

        v->val = u, v->calc();
    }
    int sum(int a, int b)
    {
        Node l, tmp, r;
        split(root, a, l, tmp), split(tmp, b + 1, tmp, r);
        int res = tmp->sum;
        root = merge(merge(l, tmp), r);
        return res;
    }
};