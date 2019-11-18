#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = INT_MAX;

int n, m;
int a[N];

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

struct Splay
{
    typedef int T;
    struct node
    {
        T v = 0;
        int ch[2] = { 0, 0 };
        int fa = 0, sum = 0, cnt = 0, tag = 0;
    } e[N];
    int sz, &root = e[0].ch[1];
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
        to = e[to].fa;
        int up;
        while((up = e[at].fa) != to) {
            if(e[up].fa != to)
                rotate(identify(up) == identify(at) ? up : at);
            rotate(at);
        }
    }
    int add_point(T v, int fa) {
        ++sz; e[sz].v = v; e[sz].fa = fa; e[sz].sum = e[sz].cnt = 1;
        return sz;
    }
    int find(int x) {
        if (x > e[root].sum) return -INF;
        int now = root;
        while (true) {
            push_down(now);
            if (x <= e[e[now].ch[0]].sum) now = e[now].ch[0];
            else if ((x -= e[e[now].ch[0]].sum) <= e[now].cnt) break;
            else x -= e[now].cnt, now = e[now].ch[1];
        }
        return now;
    }
    int build(int l, int r, int fa) {
        if (l > r) return 0;
        int mid = (l+r)>>1,
            now = add_point(mid, fa);
        e[now].ch[0] = build(l, mid-1, now);
        e[now].ch[1] = build(mid+1, r, now);
        update(now);
        return now;
    }
    void push_down(int x) {
        if (x && e[x].tag) {
            e[e[x].ch[0]].tag ^= 1;
            e[e[x].ch[1]].tag ^= 1;
            swap(e[x].ch[0], e[x].ch[1]);
            e[x].tag = 0;
        }
    }
    void reverse(int l, int r) {
        int pl = find(l-1+1), pr = find(r+1+1);
        splay(pl); splay(pr, pl);
        e[e[e[root].ch[1]].ch[0]].tag ^= 1;
    }
    void print_LMR(int x) {
        if (!x) return;
        push_down(x);
        print_LMR(e[x].ch[0]);
        if (e[x].v != 0 && e[x].v != n+1)
            write(a[e[x].v]), putchar(' ');
        print_LMR(e[x].ch[1]);
    }
} tree;

int main()
{
    read(n); read(m);
    a[0] = INT_MIN; a[n+1] = INT_MAX;
    for (int i = 1; i <= n; ++i) a[i] = i;
    tree.root = tree.build(0, n+1, 0);
    for (int i = 0, l, r; i < m; ++i) {
        read(l); read(r);
        tree.reverse(l, r);
    }
    tree.print_LMR(tree.root); putchar('\n');
    return 0;
}
