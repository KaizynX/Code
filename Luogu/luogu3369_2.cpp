#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int INF = 1e9;

struct Splay
{
    #define root e[0].ch[0]
    int n = 0;
    typedef int T;
    struct Node
    {
        T v;
        int fa = 0, sum = 0, cnt = 0;
        int ch[2] = { 0, 0 };
    } e[N];

    void update(int x) { e[x].sum = e[e[x].ch[0]].sum+e[e[x].ch[1]].sum+e[x].cnt; }
    int identify(int x) { return x == e[e[x].fa].ch[1]; }
    void connect(int x, int y, int son) { e[x].fa = y; e[y].ch[son] = x; }
    void rotate(int x) {
        int y = e[x].fa,
            r = e[y].fa,
            sonx = identify(x),
            sony = identify(y);
        connect(e[x].ch[sonx^1], y, sonx);
        connect(y, x, sonx^1);
        connect(x, r, sony);
        update(y); update(x);
    }
    void splay(int x, int y) {
        y = e[y].fa;
        int z;
        while ((z = e[x].fa) != y) {
            if (e[z].fa != y)
                identify(x) == identify(z) ? rotate(z) : rotate(x);
            rotate(x);
        }
    }
    int add_point(T v, int fa) {
        ++n; e[n].v = v; e[n].fa = fa; e[n].sum = e[n].cnt = 1; return n;
    }
    int find(T v) {
        int u = root;
        while (u && e[u].v != v) {
            u = e[u].v < v;
        }
        if (u) splay(u, root);
        return u;
    }
    void insert(T v) {
        if (!root) {
            root = add_point(v, root);
            return;
        }
        int u = root;
        while (true) {
            ++e[u].sum;
            if (e[u].v == v) {
                ++e[u].cnt;
                break;
            }
            if (!e[u].ch[e[u].v < v]) {
                u = e[u].ch[e[u].v < v] = add_point(v, u);
                break;
            }
            u = e[u].v < v;
        }
        splay(u, 0);
    }
    void erase(T v) {
        int del = find(v);
        if (!del) return;
        if (e[del].cnt > 1) {
            --e[del].cnt;
            --e[del].sum;
            splay(del, root);
            return;
        }
        if (!e[del].ch[0] && ! e[del].ch[1]) {
            root = 0;
        } else if (!e[del].ch[0]) {
            e[root = e[del].ch[1]].fa = 0;
        } else {
            int lef = e[del].ch[0];
            while (e[lef].ch[1]) lef = e[lef].ch[1];
            splay(lef, e[del].ch[0]);
            connect(e[del].ch[1], lef, 1);
            connect(lef, 0, 1);
            update(lef);
        }
    }
    int rank(T v) {
        /*
        int res = 0, u = root;
        while (u) {
            if (e[u].v == v) {
                res += e[e[u].ch[0]].sum+1;
                break;
            }
            if (e[u].v < v) u = e[u].ch[0];
            else res += e[e[u].ch[0]].sum+e[u].cnt, u = e[u].ch[1];
        }
        if (u) splay(u, 0);
        return res;
        */
        return e[e[find(v)].ch[0]].sum+1;
    }
    T atrank(int x) {
        if (x > e[root].sum) return -INF;
        int u = root;
        while (u) {
            if (x <= e[e[u].ch[0]].sum) u = e[u].ch[0];
            else if ((x -= e[e[u].ch[0]].sum) <= e[u].cnt) break;
            else x -= e[u].cnt, u = e[u].ch[1];
        }
        if (u) splay(u, root);
        return e[u].v;
    }
    int upper(T v) {
        int u = root;
        T res = INF;
        while (u) {
            if (e[u].v > v) res = min(res, e[u].v);
            u = e[u].v < v;
        }
        return res;
    }
    int lower(T v) {
        int u = root;
        T res = -INF;
        while (u) {
            if (e[u].v < v) res = max(res, e[u].v);
            u = e[u].v < v;
        }
        return res;
    }
    #undef root
} tree;

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void write(T x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

int n;

int main()
{
#ifndef DEBUG
    read(n);
#else
    cin >> n;
#endif
    for (int i = 1, opt, x; i <= n; ++i) {
#ifndef DEBUG
        read(opt);
        read(x);
#else
        cin >> opt >> x;
#endif
        switch (opt) {
            case 1 :
                tree.insert(x);
                break;
            case 2 :
                tree.erase(x);
                break;
            case 3 :
                write(tree.rank(x));
                putchar('\n');
                break;
            case 4 :
                write(tree.atrank(x));
                putchar('\n');
                break;
            case 5 :
                write(tree.lower(x));
                putchar('\n');
                break;
            case 6 :
                write(tree.upper(x));
                putchar('\n');
                break;
            // defult :
        }
    }
    return 0;
}
