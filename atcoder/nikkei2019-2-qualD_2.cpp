#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const long long INF = 1e18;

struct Node
{
    int l, r, c;
    friend bool operator < (const Node &x, const Node &y) { return x.l < y.l; }
} a[N];

struct SegmentTree
{
    typedef long long T;
    struct TreeNode
    {
        int l, r;
        T mv = INF, tag = INF;
    } tr[N<<2];
    T get(const T &x, const T &y) { return min(x, y); }
    void push_up(int i) { tr[i].mv = get(tr[i<<1].mv, tr[i<<1|1].mv); }
    void push_down(int i) {
        if (tr[i].tag == INF) return;
        tr[i<<1].tag = get(tr[i<<1].mv, tr[i].tag);
        tr[i<<1|1].tag = get(tr[i<<1|1].mv, tr[i].tag);
        tr[i<<1].mv = get(tr[i<<1].mv, tr[i].tag);
        tr[i<<1|1].mv = get(tr[i<<1|1].mv, tr[i].tag);
        tr[i].tag = INF;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) return;
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    void update(int i, int l, int r, T v) {
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].mv = get(tr[i].mv, v);
            if (tr[i].tag) tr[i].tag = get(tr[i].tag, v);
            else tr[i].tag = v;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1, l, r, v);
        if (r >  mid) update(i<<1|1, l, r, v);
        push_up(i);
    }
    T query(int i, int x) {
        if (tr[i].l == x && tr[i].r == x) return tr[i].mv;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) return query(i<<1, x);
        else return query(i<<1|1, x);
    }
} ST;

int n, m;
long long dis[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> a[i].l >> a[i].r >> a[i].c;
    sort(a+1, a+m+1);
    ST.build(1, 1, n);
    ST.update(1, 1, 1, 0);
    for (int i = 1, p = 1; i <= n; ++i) {
        dis[i] = ST.query(1, i);
        for ( ; p <= m && a[p].l <= i; ++p)
            ST.update(1, a[p].l+1, a[p].r, a[p].c+dis[i]);
    }
    cout << (dis[n] == INF ? -1 : dis[n]) << endl;
    return 0;
}
