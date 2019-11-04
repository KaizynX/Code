#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 1e9;

struct Splay
{
    #define root e[0].ch[1]
    typedef int T;
    struct node
    {
        T v = 0;
        int ch[2] = { 0, 0 };
        int fa = 0, sum = 0, cnt = 0;
    } e[N];
    int n;
    void update(int x) { e[x].sum = e[e[x].ch[0]].sum+e[e[x].ch[1]].sum+e[x].cnt; }
    int identify(int x) { return x == e[e[x].fa].ch[1]; }
    void connect(int x,int f,int son) { e[x].fa = f; e[f].ch[son] = x; }
    void rotate(int x) {
        int y = e[x].fa,
            r = e[y].fa,
            rson = identify(y),
            yson = identify(x),
            b = e[x].ch[yson^1];
        connect(b, y, yson);
        connect(y, x, yson^1);
        connect(x, r, rson);
        update(y); update(x);
    }
    void splay(int at,int to = 0) {
        // to = e[to].fa;
        int up;
        while((up = e[at].fa) != to) {
            if(e[up].fa != to)
                rotate(identify(up) == identify(at) ? up : at);
            rotate(at);
        }
    }
    int add_point(T v, int fa) {
        ++n; e[n].v = v; e[n].fa = fa; e[n].sum = e[n].cnt = 1;
        return n;
    }
    int find(T v) {
        int now = root, last = 0;
        while (now && e[now].v != v)
            last = now, now = e[now].ch[v > e[now].v];
        splay(now ? now : last);
        return now;
    }
    void insert(T v) {
        if (!root) { root = add_point(v, root); return; }
        int now = root, last = 0;
        while (now && e[now].v != v)
            last = now, now = e[now].ch[v > e[now].v];
        if (now) ++e[now].cnt;
        else now = e[last].ch[v > e[last].v] = add_point(v, last);
        splay(now);
    }
    void erase(T v) {
        int del = find(v);
        if (!del) return;
        if (e[del].cnt > 1) {
            --e[del].cnt;
            --e[del].sum;
        } else if (!e[del].ch[0]) {
            root = e[del].ch[1];
            e[root].fa = 0;
        } else {
            int oldroot = root;
            splay(nex(e[del].ch[0], 1));
            connect(e[oldroot].ch[1], root, 1);
            update(root);
        }
    }
    int rank(T v) { return e[e[find(v)].ch[0]].sum+1; }
    T atrank(int x) {
        if (x > e[root].sum) return -INF;
        int now = root;
        while (true) {
            if (x <= e[e[now].ch[0]].sum) now = e[now].ch[0];
            else if ((x -= e[e[now].ch[0]].sum) <= e[now].cnt) break;
            else x -= e[now].cnt, now = e[now].ch[1];
        }
        splay(now);
        return e[now].v;
    }
    // small 0, big 1
    int nex(int x, int opt) { while (e[x].ch[opt]) x = e[x].ch[opt]; return x; }
    T lower(T v, int opt) {
        insert(v);
        T res = e[nex(e[root].ch[opt], opt^1)].v;
        erase(v);
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
#ifdef DEBUG
    tree.insert(INF);
    tree.insert(-INF);
#endif
    read(n);
    for (int i = 1, opt, x; i <= n; ++i) {
        read(opt);
        read(x);
        switch (opt) {
            case 1 :
                tree.insert(x);
                break;
            case 2 :
                tree.erase(x);
                break;
            case 3 :
#ifdef DEBUG
                write(tree.rank(x)-1);
#else
                write(tree.rank(x));
#endif
                putchar('\n');
                break;
            case 4 :
#ifdef DEBUG
                write(tree.atrank(x+1));
#else
                write(tree.atrank(x));
#endif
                putchar('\n');
                break;
            case 5 :
                write(tree.lower(x, 0));
                putchar('\n');
                break;
            case 6 :
                write(tree.lower(x, 1));
                putchar('\n');
                break;
        }
    }
    return 0;
}
